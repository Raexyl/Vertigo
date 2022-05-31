#include "Rigidbody.h"

namespace Impact
{
	Rigidbody::Rigidbody(void)
	{
	}

	Rigidbody::Rigidbody(Shape* shape, float mass)
	{
		m_Shape = shape;
		m_Mass = mass;
	}

	Rigidbody::~Rigidbody(void)
	{
	}
}