#include "Scene.h"

namespace Impact
{
	Scene::Scene(void)
	{
	}

	Scene::~Scene(void)
	{
		for(unsigned int i = 0; i < m_Rigidbodies.size(); i++)
		{
			delete m_Rigidbodies[i];
		}
	}

	void Scene::Step(float dt)
	{
		//Step Velocities
		for(unsigned int i = 0; i < m_Rigidbodies.size(); i++)
		{
			Rigidbody* b = m_Rigidbodies[i];
			b->velocity += m_Gravity * dt; //gravity
			b->velocity *= 1 - (m_Drag * dt); //drag (air resistance)
			b->position += b->velocity * dt; //step position
		}

		BoxIn(Vec2(800, 600));

		//Manage collisions!
		for(unsigned int iterations = 0; iterations < m_Iterations; iterations++)
		{
			for(unsigned int i = 0; i < m_Rigidbodies.size() - 1; i++)
			{
				for(unsigned int j = i + 1; j < m_Rigidbodies.size(); j++)
				{
					Manifold m = Manifold(m_Rigidbodies[i], m_Rigidbodies[j]);
					m.Solve();
				}
			}
		}
	}

	void Scene::AddRigidbody(Rigidbody* rigidbody)
	{
		m_Rigidbodies.push_back(rigidbody);
	}

	void Scene::DebugDraw(sf::RenderWindow* window)
	{
		sf::CircleShape circle(50.0f);
		circle.setFillColor(sf::Color::Cyan);

		for(unsigned int i = 0; i < m_Rigidbodies.size(); i++)
		{
			Impact::Rigidbody* b = m_Rigidbodies[i];
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
		for(unsigned int i = 0; i < m_Rigidbodies.size(); i++)
		{
			Impact::Rigidbody* b = m_Rigidbodies[i];
			float x = b->position.x;
			float y = b->position.y;

			if(x > dimensions.x)
			{
				b->velocity.x = -abs(b->velocity.x);
			} else if (x < 0)
			{
				b->velocity.x = abs(b->velocity.x);
			}

			if(y > dimensions.y)
			{
				b->velocity.y = -abs(b->velocity.y);
			} else if (y < 0)
			{
				b->velocity.y = abs(b->velocity.y);
			}
		}
	}
}