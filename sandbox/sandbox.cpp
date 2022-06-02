
#include "Vertigo/Vertigo.h" //Include Vertigo game engine (includes SFML/Graphics.hpp)

class Game : public App
{
	//We need a window
	sf::RenderWindow* window;
	sf::CircleShape shape;

	Impact::Shape circle;
	Impact::Rigidbody rb;
	Impact::Rigidbody rb2;

	void OnStart()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
		
		shape = sf::CircleShape(100.0f);
		shape.setFillColor(sf::Color::Green);

		circle = Impact::Shape(50.0f);
		rb = Impact::Rigidbody(&circle, 1.0f);
		rb.position = Impact::Vec2(window->getSize().x/2, window->getSize().y/2);
		AddRigidbody(&rb);

		rb2 = Impact::Rigidbody(&circle, 1.0f);
		rb2.position = Impact::Vec2(window->getSize().x/2, window->getSize().y/4);
		AddRigidbody(&rb2);
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

		rb.velocity += Impact::Vec2(0.00f, -0.01f);
	}

	void OnRender()
	{
		window->clear();
		DebugDrawPhysics(window);
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