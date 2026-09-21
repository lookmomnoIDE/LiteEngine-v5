#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
	Renderer* m_renderer;
	Window* m_window;
	bool m_running = true;
public:
	Engine();
	~Engine();
	void update();
	void render();
	void run();
	void quit();
};

#endif