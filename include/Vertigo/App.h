#ifndef APP_H
#define APP_H

class App
{
    public:
        App();
        virtual ~App(); //Is this ok as virtual? It stops this line from getting a warning...
        virtual void     OnStart();
/*!< \brief Automatically dalled before the app's first frame.
 *
 *	Override this method in your App derivative, and it's content will be executed before the
 *	first frame is run (before App::OnUpdate() and App::OnRender() are first called.)
 */
        virtual void     OnUpdate();
/*!< \brief Automatically called once for each frame.
 *
 *	Override this method in your App derivative, and it's content will be executed during 
 *	each frame, before App::OnRender().
 *	This is where you should run all of your non-rendering-related game code.
 */
		virtual void 	 OnRender();
/*!< \brief Automatically called to render a frame.
 *
 *	Override this method in your App derivative, and it's content will be executed once per
 *	frame, after App::OnUpdate().
 *	This is where you should run all of your rendering-related code. 
 */
        virtual void     OnEnd();
/*!< \brief Automatically called after App::Quit().
 *
 *	Override this method in your App derivative, and it's content will be executed once after
 *	App::Quit() runs.
 *	This is where you should prepare your application to exit (e.g. clean up memory, de-allocate
 *	resources.) 
 */
		
		//Exit
		bool IsQuitting();
/*!< \brief Returns true if the application is exiting.
 *
 *	Returns true if the application has been told to exit in this frame. Either by App::Quit() 
 *	or by closing the window.
 */

	protected: //i.e. can be used by derivatives

		//Exit
        void Quit();
/*!< \brief Quits the application.
 *
 *	Call this method to exit the application after this frame is complete.
 */
};
/*!< \brief Application class.
 *
 *	This class is intended to be derived from (see Game.cpp for an example.)
 *	The game code should be written inside overridden methods of this class.
 *	The class that derives from App and holds the game's code, should be
 *	instantiated in GetApp().
 */


#endif