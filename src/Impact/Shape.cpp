#include "Shape.h"
#include <cmath>

#include <iostream>
#include <cfloat>

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

	bool Shape::IsCircular(void)
	{
		if(vertices.size() == 0) { return true; };
		return false;
	}

	void Shape::GetFaceNormals(std::vector<Impact::Vec2>* output)
	{
		if(IsCircular()) { return; };

		Vec2 normal;
		for(int i = 0; i < vertices.size() - 1; i++)
		{
			//Going clockwise, taking left hand normals
			normal = vertices[i+1] - vertices[i];
			normal.Normalize();
			normal = Vec2(-normal.y, normal.x);

			output->push_back(normal);
		}
		
		normal = vertices[0] - vertices[vertices.size()-1];
		normal.Normalize();
		normal = Vec2(-normal.y, normal.x);
		output->push_back(normal);
	}

	float Shape::GetExtensionAlongDir(Impact::Vec2 dir) //Doesn't account for rotation!
	{
		if(IsCircular()) { return radius; };

		float extension = -FLT_MAX;
		for(unsigned int i = 0; i < vertices.size(); i++)
		{
			float thisExt = Dot(dir, vertices[i]);
			if(thisExt > extension) { extension = thisExt; };
		}

		return extension;
	}

	float Shape::GetArea(void)
	{
		if(!IsCircular())
		{
			float sum = 0.0f;
			for(int i = 0; i < vertices.size() - 1; i++)
			{
				sum += Cross(vertices[i], vertices[i+1]);
			}
			sum += Cross(vertices[vertices.size()], vertices[0]);
			return sum / 2.0f;
		}

		return M_PI * radius * radius;
	}
}