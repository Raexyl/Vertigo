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

			void Step(float dt);
			void AddRigidbody(Rigidbody* rigidbody);
			void DebugDraw(sf::RenderWindow* window);

		private:
			std::vector<Rigidbody*> m_Rigidbodies;
	};
}

#endif