#include "App.h"

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

void App::Quit(void)
{
	m_Quitting = true;
}

void App::SetPhysicsFramerate(float framerate)
{
	m_PhysicsFrameTime = (1.0f/framerate);
}

void App::SetRenderFramerate(float framerate)
{
	m_RenderFrameTime = (1.0f/framerate);
}

bool App::IsQuitting(void)
{
	return m_Quitting;
}

float App::GetPhysicsFrameTime(void)
{
	return m_PhysicsFrameTime;
}

float App::GetRenderFrameTime(void)
{
	return m_RenderFrameTime;
}