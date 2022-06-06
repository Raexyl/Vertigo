#ifndef SCENE_H
#define SCENE_H

#include "Manifold.h"

#include <SFML/Graphics.hpp>

namespace Impact
{
	class Scene
	{
		/* ----- Enforce singleton status ----- */
		public:
			Scene(const Scene&) = delete; //Delete copy constructor
			Scene& operator=(const Scene&) = delete;	//Delete assignment operator

			static Scene& Get()
			{
				return instance;
			}

			~Scene(void);

		private:
			Scene(void);

		private:
			static Scene instance;

			Vec2 m_Gravity = Vec2(0.0f, 9.81f);
			float m_Drag = 0.00f;
			unsigned int m_Iterations = 2;

		public:
			static void Step(float dt);
			static void DebugDraw(sf::RenderWindow* window);
			static void SetGravity(Vec2 vector);
			static void SetDrag(float coefficient);
			static void SetIterations(unsigned int iterations);

		private:
			//std::vector<Rigidbody*> m_Rigidbodies;
			void hiddenStep(float dt);
			void hiddenDebugDraw(sf::RenderWindow* window);
			void hiddenSetGravity(Vec2 vector);
			void hiddenSetDrag(float coefficient);
			void hiddenSetIterations(unsigned int iterations);

			void BoxIn(Impact::Vec2 dimensions);
	};
}

#endif