
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

		smallCircle = Impact::Shape(25.0f);
		mediumCircle = Impact::Shape(50.0f);
		ideal = Impact::Material(0.99f, 0.0f, 0.0f);

		//medium circles
		for(unsigned int i = 0; i < 5; i++)
		{
			Impact::Rigidbody* body = new Impact::Rigidbody(&mediumCircle, &ideal, 1.0f);
			body->position = Impact::Vec2(i * 10.0f, i * 8.0f);
			body->velocity = Impact::Vec2(i, i) * 2.0f;
		}

		//small circles
		//for(unsigned int i = 0; i < 10; i++)
		//{
		//	Impact::Rigidbody* body = new Impact::Rigidbody(&smallCircle, &ideal, 1.0f);
		//	body->position = Impact::Vec2(i * 10.0f, i * 8.0f);
		//	body->velocity = Impact::Vec2(i, i) * 2.0f;
		//}

		//Polygon test
		std::vector<Impact::Vec2> vertices = {
			Impact::Vec2(50.0f, 50.0f),
			Impact::Vec2(25.0f, -25.0f),
			Impact::Vec2(-25.0f, 0.0f)
		};
		polyShape = Impact::Shape(vertices);
		Impact::Rigidbody* poly = new Impact::Rigidbody(&polyShape, &ideal, 1.0f);
		poly->velocity = Impact::Vec2(100.0f, 100.0f);

		//Kinematic body test
		Impact::Rigidbody* kinematic = new Impact::Rigidbody(&mediumCircle, &ideal, 0.0f);
		kinematic->position = Impact::Vec2(400, 300);
		kinematic->MakeKinematic();

		//Change scene physics
		Impact::Scene::SetGravity(Impact::Vec2(0.0f, 98.81f));

		//Change framerates test
		SetRenderFramerate(60.0f);
		SetPhysicsFramerate(120.0f);
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