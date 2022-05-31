#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Shape.h"

namespace Impact
{
	class Rigidbody
	{
		private:
			Shape* m_Shape;
			float m_Mass;

		public:
			Rigidbody();
			Rigidbody(Shape* shape, float mass);
			~Rigidbody();
	};
}

#endif