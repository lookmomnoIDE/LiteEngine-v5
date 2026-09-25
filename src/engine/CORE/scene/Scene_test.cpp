#include "Scene_test.h"



Scene_test::Scene_test(Engine* game, Renderer* renderer) 
	:Scene(game, renderer)//m_game(game), m_renderer(renderer), m_maxEntities(maxEntities)
{
	Scene_test::registerAction(GLFW_MOUSE_BUTTON_LEFT, Name::LMB); // Change place -> LMB
	Scene_test::registerAction(GLFW_KEY_ESCAPE, Name::ESC);
	Scene_test::registerAction(GLFW_KEY_P, Name::P);
	Scene_test::registerAction(GLFW_KEY_O, Name::O);
	Scene_test::registerAction(GLFW_KEY_SPACE, Name::SPACE);
	Scene_test::registerAction(GLFW_KEY_F3, Name::F3);
}


//C:\projects\LiteEngineV003\res\fonts\short
void Scene_test::init()
{
	//m_renderer->makeIndexed(loadObj(path));
}


void Scene_test::update()
{
	if(!m_paused)
	{	
		

	}
}


void Scene_test::sAnimation()
{

}


void Scene_test::sEnemySpawner()
{

}


void Scene_test::sCollision()
{

}


void Scene_test::sRender()
{

	
}


void Scene_test::sGUI()
{

}


bool Scene_test::isPaused()
{
	return m_paused;
}


void Scene_test::doAction(const Action& a)
{
	if (a.type() == Type::START)
	{
		if (a.name() == Name::LMB)
		{
			m_primaryActionActive = true;
		}

		if(a.name() == Name::SPACE)
		{
			if(m_paused == false)
			{
				m_paused = true;
			}
			else
			{
				m_paused = false;
			}
		}

		if(a.name() == Name::F3)
		{
			m_game->toggleOverlay();
		}
	}
	if(a.type() == Type::END)
	{
		if(a.name() == Name::LMB)
		{
			m_primaryActionActive = false;
		}
	}
	if (a.name() == Name::ESC)
	{
		m_game->quit();
	}
}


void Scene_test::registerAction(int keycode, const Name aName)
{
	m_actionMap[keycode] = aName;
}


std::map<int, Name>& Scene_test::getAM()
{
	std::cout << "AM size: " << m_actionMap.size() << std::endl;
	return m_actionMap;
}


void Scene_test::sDoAction()
{
	if (m_primaryActionActive)
	{
		
	}
}