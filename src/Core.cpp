#include "Core.h"
#include "Logger.h"

int main(void)
{
	Logger::SetLogLevel(Logger::logLevel::note);
	Logger::Log("Starting Core...", Logger::logLevel::note);

	//We need an app
    App* a = GetApp(); 
    if(a == nullptr) { Logger::Log("No application detected. Please define function \"App* GetApp()\".", Logger::logLevel::error); return 1; };

	Logger::Log("Starting App...", Logger::logLevel::note);
	a->OnStart();

	//Check we have a window!
	sf::RenderWindow* window = a->GetWindow();
	if(window == nullptr) { Logger::Log("No window detected. Please create an SFML window in OnStart(). Tell Vertigo to use it with SetWindow(sf::RenderWindow*)", Logger::logLevel::error); return 1; };


	Logger::Log("Beginning main loop...", Logger::logLevel::note);
    while(window->isOpen())
	{
		//poll events
		sf::Event event;
		while(window->pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window->close();
			}
		}

        a->OnUpdate();
		a->OnRender();

    }

	Logger::Log("Quitting...", Logger::note);
    a->OnEnd();
	
    delete a;
    return 0;
}
