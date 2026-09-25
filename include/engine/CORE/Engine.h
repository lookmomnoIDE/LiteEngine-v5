#ifndef ENGINE_H
#define ENGINE_H


#include "renderer.h"
#include "Scene.h"
#include "Scene_test.h"

enum class eScene
{
	NONE,
	PLAY,
	MENU,
	LOSE,
	WIN,
	CREDITS,
	SETTINGS,
	TEST,
	EDITOR,
	CUSTOM,
	COUNT
};

class Engine
{
	Renderer* m_renderer;
	Window* m_window;
	bool m_running = true;
	std::map<eScene, std::unique_ptr<Scene>> m_scenes;
	eScene m_currentScene = eScene::NONE;

public:
	Engine(Window* window, Renderer* renderer);
	~Engine(){}
	void init();
	void update(Scene* scene);
	void render(Scene* scene);
	void run();
	void quit();
	template <typename T, typename... Args>
	void changeScene(const eScene scene, Args&&... args)
	{
		if (m_currentScene != scene)
		{
			m_currentScene = scene;
			m_scenes[scene] = std::make_unique<T>(this, std::forward<Args>(args)...);
			currentScene()->init();
		}
		else if(m_currentScene == scene)
		{
			currentScene()->init();
		}
	}
	Scene* currentScene();
};

#endif