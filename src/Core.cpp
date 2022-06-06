#include "Core.h"
#include "Logger.h"

#include <iostream>

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
    while(!a->IsQuitting())
	{
        a->OnUpdate();
		Impact::Scene::Step(0.01f);
		a->OnRender();
    }

	Logger::Log("Quitting...", Logger::note);
    a->OnEnd();
	
    delete a;
    return 0;
}
