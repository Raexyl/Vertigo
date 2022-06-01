#include "Core.h"
#include "Logger.h"

#include <iostream>

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
    while(!a->IsQuitting())
	{
        a->OnUpdate();
		a->OnRender();

		Impact::Scene* physicsScene = a->GetScene();
		if(physicsScene != nullptr)
		{
			physicsScene->Step(0.01f); //Replace with actual dt at a later date
		}
    }

	Logger::Log("Quitting...", Logger::note);
    a->OnEnd();
	
    delete a;
    return 0;
}
