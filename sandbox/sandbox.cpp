
//Include Vertigo game engine
#include "Vertigo/Vertigo.h"

class Game : public App
{
	//We need a window
	sf::RenderWindow* window;

	void OnStart()
	{
		window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
		SetWindow(window);
	}

	void OnUpdate()
	{
	}

	void OnRender()
	{

	}

	void OnEnd()
	{
		delete window;
	}
};

App* GetApp(void)
{
	return new Game();
}