#include "Core.h"
#include "Logger.h"
#include "Impact/Math.h"

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

	Impact::Vec2 v1(0.5f, -3.0f);
	Impact::Vec2 v2 = Impact::Vec2(20.0f, -13.0f);
	v1 = v1 - v2;

	std::cout << v1.x << ", " << v1.y << std::endl;

	Logger::Log("Beginning main loop...", Logger::logLevel::note);
    while(!a->IsQuitting())
	{
        a->OnUpdate();
		a->OnRender();
    }

	Logger::Log("Quitting...", Logger::note);
    a->OnEnd();
	
    delete a;
    return 0;
}
