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
		float m_PhysicsFrameTime = (1/120.0f);
		float m_RenderFrameTime = (1/60.0f);

	protected:
		void Quit(void);

		//Set frame-rates
		void SetPhysicsFramerate(float framerate);
		void SetRenderFramerate(float framerate);

	public: 
		bool IsQuitting(void);

		float GetPhysicsFrameTime(void);
		float GetRenderFrameTime(void);
};
#endif