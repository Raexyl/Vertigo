#ifndef SHAPE_H
#define SHAPE_H

#include "Math.h"
#include <vector>

namespace Impact
{
	class Shape
	{
		public:
			Shape();
			Shape(float Radius);
			~Shape();

		public:
			float radius = 0.0f;				//Radius if circular, Max extension if not.
			std::vector<Vec2> vertices;
	};
}

#endif