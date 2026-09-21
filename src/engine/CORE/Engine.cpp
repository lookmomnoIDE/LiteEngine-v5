#include "engine.h"


Engine::Engine(Window* window, Renderer* renderer)
:m_renderer(renderer), m_window(window)
{

}

~Engine::Engine()
{

}

void Engine::update()
{

}


void Engine::render()
{

}

void Engine::quit()
{
	
}

void Engine::run()
{
	while(m_running)
	{
		window->PollEvents()
		update();
        render();
        window->SwapBuffers();
	}
	quit();
}