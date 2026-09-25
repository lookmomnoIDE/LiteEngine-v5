#include "engine.h"


Engine::Engine(Window* window, Renderer* renderer)
:m_renderer(renderer), m_window(window)
{

}


void Engine::init()
{
	m_window->setEnginePtr(this);
	std::string texturedVertexPath = "src/shaderCode/textured.vert";
	std::string texturedFragmentPath = "src/shaderCode/textured.frag";
	std::string defaultVertexPath = "src/shaderCode/default.vert";
	std::string defaultFragmentPath = "src/shaderCode/default.frag";
	std::string textVertexPath = "src/shaderCode/text.vert";
	std::string textFragmentPath = "src/shaderCode/text.frag";
	m_renderer->createShader("default", defaultFragmentPath, defaultVertexPath);
	m_renderer->createShader("textured", texturedFragmentPath, texturedVertexPath);
	m_renderer->createShader("text", textFragmentPath, textVertexPath);
	m_renderer->createTexture(eTexture::DEFAULT, "res/textures/default.png");
	m_renderer->createTexture(eTexture::ALBEDO, "res/textures/fabric.jpg");
	changeScene<Scene_test>(eScene::TEST, m_renderer);
}


void Engine::update(Scene* scene)
{
	scene->update();
}


void Engine::render(Scene* scene)
{
	scene->sRender();
}


void Engine::quit()
{
	
}


void Engine::run()
{
	while(m_running)
	{
		Scene scene = m_scenes.at(m_currentScene);
		window->PollEvents()
		update(scene);
        render(scene);
        window->SwapBuffers();
	}
	quit();
}


Scene* currentScene()
{
	return m_scenes.at(m_currentScene);
}