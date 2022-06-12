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
			bool m_IsKinematic = false;

			unsigned int m_AllRigidbodiesPosition;

		public:
			Vec2 position;
			Vec2 velocity;
			static std::vector<Rigidbody*> allRigidbodies;

		public:
			Rigidbody();
			Rigidbody(Shape* shape, Material* material, float mass);
			~Rigidbody();

			Shape* GetShape(void);
			Material* GetMaterial(void);
			float GetIMass(void);
			void MakeKinematic(void);
			bool IsKinematic(void);
	};
}

#endif