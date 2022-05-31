#include "Scene.h"

namespace Impact
{
	Scene::Scene(void)
	{
	}

	Scene::~Scene(void)
	{
	}

	void Scene::Step(float dt)
	{
		//STEP!
	}

	void Scene::AddRigidbody(Rigidbody* rigidbody)
	{
		m_Rigidbodies.push_back(rigidbody);
	}
}