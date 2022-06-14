#include "Core.h"
#include "Logger.h"

#include <iostream>
#include <chrono>
#include <thread>

//Private threads
void PhysicsThread(std::chrono::nanoseconds acc, std::chrono::milliseconds physicsFrametime);

Impact::Scene Impact::Scene::instance;

int main(void)
{
	Logger::SetLogLevel(Logger::logLevel::note);
	Logger::Log("Starting Core...", Logger::logLevel::note);

	//We need an app
    App* a = GetApp();
    if(a == nullptr) { Logger::Log("No application detected. Please define function \"App* GetApp()\".", Logger::logLevel::error); return 1; };

	Logger::Log("Starting App...", Logger::logLevel::note);
	a->OnStart();

	Logger::Log("Beginning main loop...", Logger::logLevel::note);
	
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end;
	std::chrono::steady_clock::duration delta;

	std::chrono::milliseconds physicsFrametime((int)(a->GetPhysicsFrameTime() * 1000.0f));  //seconds to milliseconds
	std::chrono::milliseconds renderFrametime((int)(a->GetRenderFrameTime() * 1000.0f));

	std::chrono::nanoseconds dt(0);
	std::chrono::nanoseconds renderAcc(0);

    while(!a->IsQuitting())
	{
		//Measuring frame-times
		end = std::chrono::steady_clock::now();

		delta = end - start;

		start = std::chrono::steady_clock::now();
		
		dt = std::chrono::duration_cast<std::chrono::nanoseconds>(delta);
		renderAcc += dt;

		//Running the application
		std::thread t0(&App::OnUpdate, a);
		
		//Update Physics
		std::thread t1(PhysicsThread, dt, physicsFrametime);

		//Render
		if(renderAcc >= renderFrametime)
		{
			a->OnRender();	
			renderAcc -= renderFrametime;
		}

		t0.join(); //OnUpdate()
		t1.join(); //Physics
					//Rendering
		
		//Sleep for a while, so we don't always use max cpu usage.
		//std::this_thread::sleep_for(minFrameTime - dt);
    }


	Logger::Log("Quitting...", Logger::note);
    a->OnEnd();
	
    delete a;
    return 0;
}

//Thread function for solving and stepping physics
void PhysicsThread(std::chrono::nanoseconds dt, std::chrono::milliseconds physicsFrametime)
{
	static std::chrono::nanoseconds acc(0);
	acc += dt;

	unsigned int maxIterations = 10; //Max iterations to avoid spiral of death
	while(acc >= physicsFrametime)
	{
		acc -= physicsFrametime;
		Impact::Scene::Step((physicsFrametime / 1000.0f).count());
		if(--maxIterations <= 0) { break; }; //Avoiding spiral of death. OnUpdate() and OnRender() need some time to run too.
	}
	return;
}
