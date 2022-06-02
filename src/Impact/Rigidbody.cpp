#include "Rigidbody.h"

namespace Impact
{
	Rigidbody::Rigidbody(void)
	{
	}

	Rigidbody::Rigidbody(Shape* shape, float mass)
	{
		m_Shape = shape;
		m_IMass = 1.0f / mass;
	}

	Rigidbody::~Rigidbody(void)
	{
	}

	Shape* Rigidbody::GetShape(void)
	{
		return m_Shape;
	}

	float Rigidbody::GetIMass(void)
	{
		return m_IMass;
	}
}