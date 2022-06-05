
#include "Vertigo/Vertigo.h" //Include Vertigo game engine (includes SFML/Graphics.hpp)
#include <iostream>


class Game : public App
{
	//We need a window
	sf::RenderWindow* window;

	//Physics
	//Impact::Scene scene;
	Impact::Shape smallCircle;
	Impact::Shape mediumCircle;

	void OnStart()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");

		smallCircle = Impact::Shape(25.0f);
		mediumCircle = Impact::Shape(50.0f);

		for(unsigned int i = 0; i < 40; i++)
		{
			Impact::Rigidbody* body = new Impact::Rigidbody(&mediumCircle, 1.0f);
			body->position = Impact::Vec2(i * 10.0f, i * 8.0f);
			body->velocity = Impact::Vec2(i, i) * 2.0f;
		}




		for(unsigned int i = 0; i < 40; i++)
		{
			Impact::Rigidbody* body = new Impact::Rigidbody(&smallCircle, 1.0f);
			body->position = Impact::Vec2(i * 10.0f, i * 8.0f);
			body->velocity = Impact::Vec2(i, i) * 2.0f;
		}

		//Change scene physics
		//scene.SetDrag(0.1f);
		//scene.SetGravity(Impact::Vec2(0.0f, 3.0f));
	}

	void OnUpdate()
	{
		std::cout << "Here!" << std::endl;

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

		//Step physics
		//scene.Step(0.01f);
	}

	void OnRender()
	{
		window->clear();
		//scene.DebugDraw(window);
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