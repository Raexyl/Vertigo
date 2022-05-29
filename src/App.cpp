#include "App.h"

#include "Renderer.h"
#include "Input.h"
#include "Logger.h"

 
App::App()
{
}

App::~App()
{
}

void App::OnStart()
{
    Logger::Log("App::OnStart() has not been overridden by a derivative of this class.", Logger::logLevel::warning);
}

void App::OnUpdate()
{
	Logger::Log("App::OnUpdate() has not been overridden by a derivative of this class.", Logger::logLevel::warning);
}

void App::OnRender()
{
	Logger::Log("App::OnRender() has not been overridden by a derivative of this class.", Logger::logLevel::warning);
}

void App::OnEnd()
{
	Logger::Log("App::OnEnd() has not been overridden by a derivative of this class.", Logger::logLevel::warning);
}


/* ----- Exit ----- */
void App::Quit()
{
    glfwSetWindowShouldClose(Renderer::GetWindow(), true);
}

bool App::IsQuitting()
{
    return glfwWindowShouldClose(Renderer::GetWindow());
}
