#ifndef SHAPE_H
#define SHAPE_H

#include "Math.h"

namespace Impact
{
	class Shape
	{
		private:
			float m_Radius = 0.0f;				//Radius if circular, Max extension if not.

		public:
			Shape();
			Shape(float radius);
			~Shape();

			float GetRadius(void);
	};
}

#endif