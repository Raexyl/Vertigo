#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Shape.h"
#include "Material.h"
#include <vector>

namespace Impact
{
	class Rigidbody
	{
		private:
			Shape* m_Shape;
			Material* m_Material;
			float m_IMass;

		public:
			Vec2 position;
			Vec2 velocity;
			static std::vector<Rigidbody*> allRigidbodies;

		public:
			Rigidbody();
			Rigidbody(Shape* shape, float mass);
			~Rigidbody();

			Shape* GetShape(void);
			Material* GetMaterial(void);
			float GetIMass(void);
	};
}

#endif