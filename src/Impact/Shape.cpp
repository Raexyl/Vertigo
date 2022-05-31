#include "Shape.h"

namespace Impact
{
	Shape::Shape(void)
	{
	}

	Shape::Shape(float radius)
	{
		m_Radius = radius;
	}

	Shape::~Shape(void)
	{
	}

	float Shape::GetRadius(void)
	{
		return m_Radius;
	}
}