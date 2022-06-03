#include "Scene.h"

namespace Impact
{
	Scene::Scene(void)
	{
	}

	Scene::~Scene(void)
	{
	}

	void Scene::Step(float dt)
	{
		//Step Velocities
		for(unsigned int i = 0; i < Rigidbody::allRigidbodies.size(); i++)
		{
			Rigidbody* b = Rigidbody::allRigidbodies[i];
			b->velocity += m_Gravity * dt; //gravity
			b->velocity *= 1 - (m_Drag * dt); //drag (air resistance)
			b->position += b->velocity * dt; //step position
		}

		BoxIn(Vec2(800, 600));

		//Manage collisions!
		for(unsigned int iterations = 0; iterations < m_Iterations; iterations++)
		{
			for(unsigned int i = 0; i < Rigidbody::allRigidbodies.size() - 1; i++)
			{
				for(unsigned int j = i + 1; j < Rigidbody::allRigidbodies.size(); j++)
				{
					Manifold m = Manifold(Rigidbody::allRigidbodies[i], Rigidbody::allRigidbodies[j]);
					m.Solve();
				}
			}
		}
	}

	void Scene::DebugDraw(sf::RenderWindow* window)
	{
		sf::CircleShape circle(50.0f);
		// circle.setFillColor(sf::Color::Cyan);

		for(unsigned int i = 0; i < Rigidbody::allRigidbodies.size(); i++)
		{
			Impact::Rigidbody* b = Rigidbody::allRigidbodies[i];
			float radius = b->GetShape()->GetRadius();
			circle.setRadius(radius);
			Impact::Vec2 pos = b->position;
			circle.setPosition(pos.x - radius, pos.y - radius); //-pos.y ? because sfml y+ is down?
			window->draw(circle);
		}
	}

	void Scene::SetGravity(Vec2 vector)
	{
		m_Gravity = vector;
	}

	void Scene::SetDrag(float coefficient)
	{
		m_Drag = coefficient;
	}

	void Scene::SetIterations(unsigned int iterations)
	{
		m_Iterations = iterations;
	}

	void Scene::BoxIn(Vec2 dimensions)
	{
		for(unsigned int i = 0; i < Rigidbody::allRigidbodies.size(); i++)
		{
			Impact::Rigidbody* b = Rigidbody::allRigidbodies[i];
			float x = b->position.x;
			float y = b->position.y;

			if(x > dimensions.x)
			{
				b->velocity.x = -abs(b->velocity.x);
				b->position.x = dimensions.x;
			} else if (x < 0)
			{
				b->velocity.x = abs(b->velocity.x);
				b->position.x = 0;
			}

			if(y > dimensions.y)
			{
				b->velocity.y = -abs(b->velocity.y);
				b->position.y = dimensions.y;
			} else if (y < 0)
			{
				b->velocity.y = abs(b->velocity.y);
				b->position.y = 0;
			}
		}
	}
}