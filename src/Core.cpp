#include "Core.h"
#include "Logger.h"

#include <iostream>
#include <chrono>

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
	std::chrono::nanoseconds acc(0);

	std::chrono::milliseconds physicsFrametime((int)(a->GetPhysicsFrameTime() * 1000.0f));  //seconds to milliseconds
	std::chrono::milliseconds renderFrametime((int)(a->GetRenderFrameTime() * 1000.0f));

	std::chrono::nanoseconds renderAcc(0);

    while(!a->IsQuitting())
	{
		//Measuring frame-times
		end = std::chrono::steady_clock::now();
		delta = end - start;
		start = std::chrono::steady_clock::now();
		
		acc += std::chrono::duration_cast<std::chrono::nanoseconds>(delta);
		renderAcc += std::chrono::duration_cast<std::chrono::nanoseconds>(delta);


		//Running the application
		a->OnUpdate();
		
		//Update Physics
		unsigned int maxIterations = 10; //Max iterations to avoid spiral of death
		while(acc >= physicsFrametime)
		{
			acc -= physicsFrametime;
			Impact::Scene::Step(a->GetPhysicsFrameTime());
			if(--maxIterations <= 0) { break; }; //Avoiding spiral of death. OnUpdate() and OnRender() need some time to run too.
		}

		//Render
		if(renderAcc >= renderFrametime)
		{
			a->OnRender();
			renderAcc = std::chrono::nanoseconds::zero();
		}
    }


	Logger::Log("Quitting...", Logger::note);
    a->OnEnd();
	
    delete a;
    return 0;
}
