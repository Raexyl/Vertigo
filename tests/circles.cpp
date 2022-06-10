
#include "Vertigo/Vertigo.h" //Include Vertigo game engine (includes SFML/Graphics.hpp)

class Game : public App
{
	//We need a window
	sf::RenderWindow* window;

	//Physics
	Impact::Shape smallCircle;
	Impact::Shape mediumCircle;
	Impact::Material idealish;

	void OnStart()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");

		smallCircle = Impact::Shape(25.0f);
		mediumCircle = Impact::Shape(50.0f);
		idealish = Impact::Material(0.9f, 0.0f, 0.0f);

		//medium circles
		for(unsigned int i = 0; i < 5; i++)
		{
			Impact::Rigidbody* body = new Impact::Rigidbody(&mediumCircle, &idealish, 1.0f);
			body->position = Impact::Vec2(i * 1.0f, 1.0f);
		}

		//small circles
		for(unsigned int i = 0; i < 100; i++)
		{
			Impact::Rigidbody* body = new Impact::Rigidbody(&smallCircle, &idealish, 1.0f);
			body->position = Impact::Vec2(i * 1.0f, 0.0f);
		}

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