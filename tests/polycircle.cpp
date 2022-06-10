
#include "Vertigo/Vertigo.h" //Include Vertigo game engine (includes SFML/Graphics.hpp)

class Game : public App
{
	//We need a window
	sf::RenderWindow* window;

	//Physics
	Impact::Shape smallCircle;
	Impact::Shape mediumCircle;
	Impact::Shape polyShape;
	Impact::Material ideal;

	void OnStart()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");

		//Shapes
		mediumCircle = Impact::Shape(50.0f);
		std::vector<Impact::Vec2> vertices = {
			Impact::Vec2(50.0f, 50.0f),
			Impact::Vec2(25.0f, -25.0f),
			Impact::Vec2(-25.0f, 0.0f)
		};
		polyShape = Impact::Shape(vertices);

		//Material
		ideal = Impact::Material(1.0f, 0.0f, 0.0f);

		//Rigidbodies
		Impact::Rigidbody* body0 = new Impact::Rigidbody(&mediumCircle, &ideal, 1.0f);
		body0->position = Impact::Vec2(100.0f, 100.0f);

		Impact::Rigidbody* body1 = new Impact::Rigidbody(&mediumCircle, &ideal, 1.0f);
		body1->position = Impact::Vec2(300.0f, 100.0f);

		Impact::Rigidbody* poly0 = new Impact::Rigidbody(&polyShape, &ideal, 1.0f);
		poly0->position = Impact::Vec2(100.0f, 500.0f);
		poly0->MakeKinematic();

		Impact::Rigidbody* poly1 = new Impact::Rigidbody(&polyShape, &ideal, 1.0f);
		poly1->position = Impact::Vec2(300.0f, 500.0f);

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