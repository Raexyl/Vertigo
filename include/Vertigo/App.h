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
		bool m_Quitting = false;

	protected:
		void Quit(void);

	public: 
		bool IsQuitting(void);
};
#endif