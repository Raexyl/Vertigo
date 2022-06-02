#ifndef SCENE_H
#define SCENE_H

#include "Manifold.h"

#include <SFML/Graphics.hpp>

#include <vector>

namespace Impact
{
	class Scene
	{
		public:
			Scene(void);
			~Scene(void);

		private:
			Vec2 m_Gravity = Vec2(0.0f, 1.0f);
			float m_Drag = 0.01f;
			unsigned int m_Iterations = 2;

		public:
			void Step(float dt);
			void AddRigidbody(Rigidbody* rigidbody);
			void DebugDraw(sf::RenderWindow* window);
			void SetGravity(Vec2 vector);
			void SetDrag(float coefficient);
			void SetIterations(unsigned int iterations);

		private:
			std::vector<Rigidbody*> m_Rigidbodies;

			void BoxIn(Impact::Vec2 dimensions);
	};
}

#endif