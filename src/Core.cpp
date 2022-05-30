#include "Core.h"
#include "Logger.h"

#include <SFML/Graphics.hpp>

int main(void)
{
	Logger::SetLogLevel(Logger::logLevel::note);
	Logger::Log("Starting Core...", Logger::logLevel::note);

	//We need a window
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	//We need an app
    App* a = GetApp(); 
    if(a == nullptr) { Logger::Log("No application detected. Please define function \"App* GetApp()\".", Logger::logLevel::error); return 1; };

	Logger::Log("Starting App...", Logger::logLevel::note);
	a->OnStart();

	Logger::Log("Beginning main loop...", Logger::logLevel::note);
    do
    {
        a->OnUpdate();
		a->OnRender();
    } while(window.isOpen());

	Logger::Log("Quitting...", Logger::note);
    a->OnEnd();
	
    delete a;
    return 0;
}
