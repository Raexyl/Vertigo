
#include "Vertigo/Vertigo.h" //Include Vertigo game engine (includes SFML/Graphics.hpp)
#include <iostream>


class Game : public App
{
	//We need a window
	sf::RenderWindow* window;

	//Physics
	Impact::Shape smallCircle;
	Impact::Shape mediumCircle;

	void OnStart()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");

		smallCircle = Impact::Shape(25.0f);
		mediumCircle = Impact::Shape(50.0f);

		//medium circles
		for(unsigned int i = 0; i < 40; i++)
		{
			Impact::Rigidbody* body = new Impact::Rigidbody(&mediumCircle, 1.0f);
			body->position = Impact::Vec2(i * 10.0f, i * 8.0f);
			body->velocity = Impact::Vec2(i, i) * 2.0f;
		}

		//small circles
		for(unsigned int i = 0; i < 40; i++)
		{
			Impact::Rigidbody* body = new Impact::Rigidbody(&smallCircle, 1.0f);
			body->position = Impact::Vec2(i * 10.0f, i * 8.0f);
			body->velocity = Impact::Vec2(i, i) * 2.0f;
		}

		//Change scene physics
		Impact::Scene::SetDrag(0.1f);
		Impact::Scene::SetGravity(Impact::Vec2(0.0f, 3.0f));
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