
#include "Vertigo/Vertigo.h" //Include Vertigo game engine (includes SFML/Graphics.hpp)

class Game : public App
{
	//We need a window
	sf::RenderWindow* window;

	//Physics
	Impact::Shape smallCircle;
	Impact::Shape mediumCircle;
	Impact::Shape bigCircle;
	Impact::Material idealish;

	void OnStart()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");

		smallCircle = Impact::Shape(15.0f);
		mediumCircle = Impact::Shape(20.0f);
		bigCircle = Impact::Shape(25.0f);
		idealish = Impact::Material(0.98f, 0.0f, 0.0f);

		//Change scene physics
		Impact::Scene::SetGravity(Impact::Vec2(0.0f, 98.81f));
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
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				static unsigned int count = 0;
				Impact::Rigidbody* newBody;
				if(count % 3 == 0)
				{
					newBody = new Impact::Rigidbody(&bigCircle, &idealish, 1.0f);
				}
				else if (count % 3 == 1)
				{
					newBody = new Impact::Rigidbody(&mediumCircle, &idealish, 1.0f);
				}
				else
				{
					newBody = new Impact::Rigidbody(&smallCircle, &idealish, 1.0f);
				}
				newBody->position = Impact::Vec2(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
				count++;
			}
		}
	}

	void OnRender()
	{
		window->clear();
		Impact::Scene::DebugDraw(window);
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