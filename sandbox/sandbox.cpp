
//Include Vertigo game engine
#include "Vertigo/Vertigo.h"

class Game : public App
{
	//We need a window
	sf::RenderWindow* window;

	sf::CircleShape shape;


	void OnStart()
	{
		window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
		
		shape = sf::CircleShape(100.0f);
		shape.setFillColor(sf::Color::Green);
	}

	void OnUpdate()
	{
		//poll events
		sf::Event event;
		while(window->pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window->close();
				Quit();
			}
		}
	}

	void OnRender()
	{
		window->clear();
        window->draw(shape);
        window->display();
	}

	void OnEnd()
	{
		delete window;
	}
};

App* GetApp(void)
{
	return new Game();
}