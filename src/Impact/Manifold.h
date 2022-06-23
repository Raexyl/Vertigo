#ifndef MANIFOLD_H
#define MANIFOLD_H

#include "Rigidbody.h"

namespace Impact
{
	enum CollType {CircleCircle, PolyCircle, PolyPoly};

	class Manifold
	{
		private:
			Rigidbody* m_A;
			Rigidbody* m_B;

			CollType m_CollType;

			//collision info, populated during solving
			float m_Penetration;
			Vec2 m_VelDif;
			Vec2 m_Normal;
			Vec2 m_Contacts[2]; //Contact point in world space
			unsigned int m_ContactNo = 0;

		public:
			Manifold(void);
			Manifold(Rigidbody* a, Rigidbody* b);
			~Manifold(void);

			void Solve(void);

		private:
			bool Overlaps(void);
			void Collide(void);
			void ApplyLinearProjection(void);

			/* ----- Shape-specific functions ----- */
			bool CircleCircleOverlaps(void);
			bool PolyCircleOverlaps(void);
			bool PolyPolyOverlaps(void);
	};
}



#endif