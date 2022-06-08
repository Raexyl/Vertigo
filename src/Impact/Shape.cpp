#include "Shape.h"
#include <cmath>

#include <iostream>

namespace Impact
{
	Shape::Shape(void)
	{
	}

	Shape::Shape(float Radius)
	{
		radius = Radius;
	}

	Shape::Shape(std::vector<Vec2> _vertices)
	:vertices(_vertices)
	{
		//We still need to assign the maximum extension as the "radius"
		for(unsigned int i = 0; i < _vertices.size(); i++)
		{
			float sizesqrd = _vertices[i].SizeSquared();
			if(sizesqrd > radius)
			{
				radius = sizesqrd;
			}
		}
		radius = sqrt(radius);
	}

	Shape::~Shape(void)
	{
	}
}