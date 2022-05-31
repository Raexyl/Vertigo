#ifndef SCENE_H
#define SCENE_H

#include "Rigidbody.h"

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

		private:
			std::vector<Rigidbody*> m_Rigidbodies;


	};
}

#endif