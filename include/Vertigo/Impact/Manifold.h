#ifndef MANIFOLD_H
#define MANIFOLD_H

#include "Rigidbody.h"

namespace Impact
{
	class Manifold
	{
		private:
			Rigidbody* m_A;
			Rigidbody* m_B;

			//collision info, populated during solving
			float m_Penetration;
			Vec2 m_VelDif;
			Vec2 m_Normal;

		public:
			Manifold(void);
			Manifold(Rigidbody* a, Rigidbody* b);
			~Manifold(void);

			void Solve(void);

		private:
			bool Overlaps(void);
			void Collide(void);
	};
}



#endif