#include "Rigidbody.h"
#include "Scene.h"
#include "Logger.h"

namespace Impact
{	
	std::vector<Rigidbody*> Rigidbody::allRigidbodies;

	Rigidbody::Rigidbody(void)
	{
		//allRigidbodies.push_back(this); //Don't add the body since it has no shape or material.
	}

	Rigidbody::Rigidbody(Shape* shape, Material* material)
		:m_Shape(shape), m_Material(material)
	{
		//Calculate mass
		m_IMass = 1.0f / (shape->GetArea() * material->density);

		allRigidbodies.push_back(this);
	}

	Rigidbody::~Rigidbody(void)
	{
		for(int i = 0; i < allRigidbodies.size(); i++)
		{
			if(allRigidbodies[i] == this)
			{
				allRigidbodies.erase(allRigidbodies.begin() + i);
				return;
			}
		}
	}

	Shape* Rigidbody::GetShape(void)
	{
		return m_Shape;
	}

	Material* Rigidbody::GetMaterial(void)
	{
		return m_Material;
	}

	float Rigidbody::GetIMass(void)
	{
		return m_IMass;
	}

	void Rigidbody::MakeKinematic(void)
	{
		m_IMass = 0.0f;
		m_IsKinematic = true;
	}

	bool Rigidbody::IsKinematic(void)
	{
		return m_IsKinematic;
	}

	void Rigidbody::ApplyImpulse(Vec2 impulse)
	{
		velocity += impulse * m_IMass;
	}
}