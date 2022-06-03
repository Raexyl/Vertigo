#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Shape.h"
#include <vector>

namespace Impact
{
	class Rigidbody
	{
		private:
			Shape* m_Shape;
			float m_IMass;

		public:
			Vec2 position;
			Vec2 velocity;

		public:
			Rigidbody();
			Rigidbody(Shape* shape, float mass);
			~Rigidbody();

			Shape* GetShape(void);
			float GetIMass(void);
	};
}

#endif