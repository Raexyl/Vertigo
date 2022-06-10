#ifndef SHAPE_H
#define SHAPE_H

#include "Math.h"
#include <vector>

namespace Impact
{
	class Shape
	{
		public:
			float radius = 0.0f;				//Radius if circular, Max extension if not
			std::vector<Vec2> vertices;

		public:
			Shape();
			Shape(float Radius);
			Shape(std::vector<Vec2> _vertices);
			~Shape();
			
			bool IsCircular(void);
			void GetFaceNormals(std::vector<Impact::Vec2>* output);
			float GetExtensionAlongDir(Impact::Vec2 dir);
	};
}

#endif