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
		for(unsigned int i = 0; i < m_Rigidbodies.size(); i++)
		{
			Rigidbody* b = m_Rigidbodies[i];
			b->position += b->velocity * dt;
		}

		//Manage collisions!
		for(unsigned int i = 0; i < m_Rigidbodies.size() - 1; i++)
		{
			for(unsigned int j = i; j < m_Rigidbodies.size(); j++)
			{
				Manifold m = Manifold(m_Rigidbodies[i], m_Rigidbodies[j]);
				m.Solve();
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
			circle.setPosition(pos.x - radius, window->getSize().y -pos.y - radius); //-pos.y because sfml y+ is down.
			window->draw(circle);
		}
	}
}