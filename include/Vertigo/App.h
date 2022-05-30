#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>

class App
{
    public:
        App();
        virtual ~App(); //Is this ok as virtual? It stops this line from getting a warning...
        virtual void     OnStart();
        virtual void     OnUpdate();
		virtual void 	 OnRender();
        virtual void     OnEnd();

	private:
		sf::RenderWindow* m_Window;

	protected:
		void SetWindow(sf::RenderWindow* window);

	public: 
		sf::RenderWindow* GetWindow(void);
};
#endif