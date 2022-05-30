
//Include Vertigo game engine
#include "Vertigo/Vertigo.h"

class Game : public App
{
	void OnStart()
	{
	}

	void OnUpdate()
	{
	}

	void OnRender()
	{

	}

	void OnEnd()
	{
	}
};

App* GetApp(void)
{
	return new Game();
}