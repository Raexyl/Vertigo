#include "Manifold.h"

#include <iostream>

namespace Impact
{
	Manifold::Manifold(void)
	{
	}

	Manifold::Manifold(Rigidbody* a, Rigidbody* b)
	{
		m_A = a;
		m_B = b;
	}

	Manifold::~Manifold(void)
	{
	}

	void Manifold::Solve(void)
	{
		if(!Overlaps()) { return; };

		Collide();
	}

	bool Manifold::Overlaps(void)
	{
		Vec2 posDif = m_B->position - m_A->position;
		m_Normal = posDif.Normalized();
		m_Penetration = posDif.Size() - m_A->GetShape()->GetRadius() - m_B->GetShape()->GetRadius();

		if (m_Penetration < 0) { return true; };
		return false;
	}

	void Manifold::Collide(void)
	{
		m_VelDif = m_B->velocity - m_A->velocity;

		if(Dot(m_Normal, m_VelDif) > 0.0f ) { return; };

		m_A->velocity *= -1.0f;
		m_B->velocity *= -1.0f;
	}
}