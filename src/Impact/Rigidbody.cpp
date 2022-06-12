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

	Rigidbody::Rigidbody(Shape* shape, Material* material, float mass)
		:m_Shape(shape), m_Material(material)
	{
		if(mass != 0.0f) 
		{
			m_IMass = 1.0f / mass;
		}
		else
		{
			m_IMass = 0.0f;
			m_IsKinematic = true;
		}

		m_AllRigidbodiesPosition = allRigidbodies.size(); //Remembering the position makes for faster deletion of rigidbodies
		allRigidbodies.push_back(this);
	}

	Rigidbody::~Rigidbody(void)
	{
		allRigidbodies.erase(allRigidbodies.begin() + m_AllRigidbodiesPosition);
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
}