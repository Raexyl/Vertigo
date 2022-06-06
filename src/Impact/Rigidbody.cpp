#include "Rigidbody.h"
#include "Scene.h"
#include "Logger.h"

namespace Impact
{	
	std::vector<Rigidbody*> Rigidbody::allRigidbodies;

	Rigidbody::Rigidbody(void)
	{
		allRigidbodies.push_back(this);
	}

	Rigidbody::Rigidbody(Shape* shape, float mass)
	{
		m_Shape = shape;
		m_IMass = 1.0f / mass;
		allRigidbodies.push_back(this);
	}

	Rigidbody::~Rigidbody(void)
	{
		//allRigidbodies.erase(this);
	}

	Shape* Rigidbody::GetShape(void)
	{
		return m_Shape;
	}

	float Rigidbody::GetIMass(void)
	{
		return m_IMass;
	}
}