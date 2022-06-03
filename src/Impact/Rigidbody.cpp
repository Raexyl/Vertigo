#include "Rigidbody.h"
#include "Scene.h"

namespace Impact
{	
	Rigidbody::Rigidbody(void)
	{
		Scene::m_Rigidbodies.push_back(this);
	}

	Rigidbody::Rigidbody(Shape* shape, float mass)
	{
		m_Shape = shape;
		m_IMass = 1.0f / mass;
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