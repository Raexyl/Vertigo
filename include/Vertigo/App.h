#ifndef APP_H
#define APP_H

#include "Impact.h"

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
		Impact::Scene* m_Scene;

	protected:
		void Quit(void);

		//Physics-related
		void SetGravity(float g);

	public: 
		bool IsQuitting(void);
};
#endif