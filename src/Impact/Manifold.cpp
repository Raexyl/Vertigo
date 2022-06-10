#include "Manifold.h"

#include <iostream>
#include <cfloat>

namespace Impact
{
	Manifold::Manifold(void)
	{
	}

	Manifold::Manifold(Rigidbody* a, Rigidbody* b)
	{
		m_A = a;
		m_B = b;

		//Is it CircleCircle, PolyCircle or PolyPoly?! Assigned here!
		if(m_A->GetShape()->IsCircular())
		{
			if(m_B->GetShape()->IsCircular())
			{
				//Both circles
				m_CollType = CircleCircle;
			}
			else
			{
				//A is circle, B is poly. SWAP!
				//This ensures in PolyCircle manifolds, the poly is always m_A and the circle is always m_B.
				m_B = a;
				m_A = b;
				m_CollType = PolyCircle;
			}
		}
		else
		{
			if(m_B->GetShape()->IsCircular())
			{
				//A is poly, B is circle
				m_CollType = PolyCircle;
			}
			else
			{
				//Both Polys
				m_CollType = PolyPoly;
			}
		}
	}

	Manifold::~Manifold(void)
	{
	}

	void Manifold::Solve(void)
	{
		//Early out if both kinematic
		if(m_A->IsKinematic() && m_B->IsKinematic()) { return; };

		//Physics
		if(!Overlaps()) { return; };
		Collide();
		ApplyLinearProjection();
	}

	bool Manifold::Overlaps(void)
	{
		switch(m_CollType)
		{
			case CircleCircle:
				return CircleCircleOverlaps();
			
			case PolyCircle:
				return PolyCircleOverlaps();

			default:
				return false; //There's something funky happening if we get to this line, so let's play it safe.
		}
	}

	void Manifold::Collide(void) //Resolve the collision
	{
		m_VelDif = m_B->velocity - m_A->velocity;

		//Quit if they are already moving apart
		float velAlongNormal = Dot(m_Normal, m_VelDif);
		if(velAlongNormal > 0.0f) { return; };

		float e = m_A->GetMaterial()->restitution + m_B->GetMaterial()->restitution;
		e /= 2.0f;
		
		float j = -(1 + e) * velAlongNormal;
		j /= m_A->GetIMass() + m_B->GetIMass();
		
		Vec2 impulse = m_Normal * j;
		
		if(!m_A->IsKinematic()) { m_A->velocity -= impulse * m_A->GetIMass(); };
		if(!m_B->IsKinematic()) { m_B->velocity += impulse * m_B->GetIMass(); };
	}

	void Manifold::ApplyLinearProjection(void) //Make sure objects are no longer overlapping
	{
		if(m_Penetration > 0) { return; };
		float adjustment = 0.5f * m_Penetration;
		if(!m_A->IsKinematic()) { m_A->position += m_Normal * adjustment; };
		if(!m_B->IsKinematic()) { m_B->position -= m_Normal * adjustment; };
	}

	/* ----- Shape-specific functions! ----- */

	bool Manifold::CircleCircleOverlaps(void)
	{
		Vec2 posDif = m_B->position - m_A->position;
		m_Normal = posDif.Normalized();
		m_Penetration = posDif.Size() - m_A->GetShape()->radius - m_B->GetShape()->radius;

		if (m_Penetration < 0) 
		{
			m_Contacts[0] = m_A->position + (posDif * m_B->GetShape()->radius);
			return true;
		}

		return false;
	}

	bool Manifold::PolyCircleOverlaps(void)
	{
		//Get axes to test for separation
		std::vector<Impact::Vec2> axes;
		m_A->GetShape()->GetFaceNormals(&axes);
		Vec2 posDif = m_B->position - m_A->position;
		axes.push_back(posDif.Normalized());

		//Get min axis of separation
		float minSep = -FLT_MAX;
		Vec2 normal = Vec2(1.0f, 0.0f);
		float posDifSize = posDif.Size();
		float penetration = 0;
		for(int i = 0; i < axes.size(); i++)
		{
			penetration = Dot(posDif, axes[i]) - m_A->GetShape()->GetExtensionAlongDir(axes[i]) - m_B->GetShape()->radius;
			if(penetration > 0)
			{
				//Doesn't overlap. We've found an axis of separation!
				return false;
			}
			else if (penetration > minSep)
			{
				minSep = penetration;
				normal = axes[i];
			}
		}

		m_Penetration = penetration;

		if(Dot(normal, posDif) < 0) { normal *= -1.0f; };
		m_Normal = normal;

		std::cout << m_Normal.x << ", " << m_Normal.y << std::endl;

		//Get contact point ( I think there's only ever one?)

		return true;
	}
}