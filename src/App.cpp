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

bool App::IsQuitting(void)
{
	return m_Quitting;
}