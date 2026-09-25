#include "Scene_test.h"
#include "GameEngine.h"



struct UIArea
{
	Vec2<float> pos;
	Vec4<float> color;
	Vec2<float> dims;
	std::vector<Vec2<float>> texCoords;
};


#include <cmath>
#include <algorithm>
#include <stdexcept>

float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
float red[4] = {1.0f, 0.0f, 0.0f, 1.0f};


Scene_test::Scene_test(GameEngine* game, Renderer* renderer, size_t maxEntities) 
	:Scene(game, renderer, maxEntities)//m_game(game), m_renderer(renderer), m_maxEntities(maxEntities)
{
	Scene_test::registerAction(GLFW_MOUSE_BUTTON_LEFT, Type::LMB); // Change place -> LMB
	Scene_test::registerAction(GLFW_KEY_ESCAPE, Type::ESC);
	Scene_test::registerAction(GLFW_KEY_P, Type::P);
	Scene_test::registerAction(GLFW_KEY_O, Type::O);
	Scene_test::registerAction(GLFW_KEY_SPACE, Type::SPACE);
	Scene_test::registerAction(GLFW_KEY_F3, Type::F3);
}


//C:\projects\LiteEngineV003\res\fonts\short
void Scene_test::init()
{
	//static Quad<T> tRect(Vec2<T> pos, Vec4<T> color, Vec2<T> dims, std::vector<Vec2<T>> texCoords)
	Vec2<float> pos = Vec2<float>(0.0f, -0.75f);
	Vec4<float> color = Vec4<float>(0.0f, 0.0f, 1.0f, 1.0f);
	Vec2<float> dims = Vec2<float>(1.0f, 0.29f);
	std::vector<Vec2<float>> texCoords = std::vector<Vec2<float>>{Vec2<float>(1.0f, 0.0f), Vec2<float>(1.0f, 1.0f), Vec2<float>(0.0f, 0.0f), Vec2<float>(0.0f, 1.0f)};
	tQuad<float> tquad = GConstructor::tRect(pos, color, dims, texCoords);
	m_tQuads.push_back(tquad);
	//m_renderer->addQuadBufferT(m_tQuads);
	pos = Vec2<float>(0.0f, 0.98f);
	color = Vec4<float>(0.0f, 0.0f, 1.0f, 1.0f);
	dims = Vec2<float>(1.0f, 0.02f);
	texCoords = std::vector<Vec2<float>>{Vec2<float>(1.0f, 0.0f), Vec2<float>(1.0f, 1.0f), Vec2<float>(0.0f, 0.0f), Vec2<float>(0.0f, 1.0f)};
	tquad = GConstructor::tRect(pos, color, dims, texCoords);
	m_tQuads.push_back(tquad);
	m_renderer->addQuadBufferT(m_tQuads);

	//UIArea toolbar{pos, color, dims, texCoords};

	//m_renderer->initTextBuffer(256);

}


void Scene_test::update()
{
	if(!m_paused)
	{	
		
		if(m_frameCounter % 60 == 0)
		{
			thyKingdom.hiddenPop *= 1.002;
			thyKingdom.population = thyKingdom.hiddenPop;
			thyKingdom.militaryPower = thyKingdom.population * thyKingdom.conscriptionRate;
			m_dayCounter++;
			m_date = TKHelpers::calculateDate(m_dayCounter);
			m_frameCounter = 0;
		}
		m_frameCounter++;
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
	m_renderer->Clear();
	m_renderer->DrawElements("default");
	m_renderer->drawText(m_date, 50.0f, 950.0f, "IBM", 1.0f, white);
	m_renderer->drawText("Population: " + std::to_string(thyKingdom.population), 50.0f, 850.0f, "IBM", 1.0f, white);
	m_renderer->drawText("Military Power: " + std::to_string(thyKingdom.militaryPower), 50.0f, 750.0f, "IBM", 1.0f, white);
	if(m_paused)
	{
		m_renderer->drawText("Paused", ((1920.0/2.0f)-5.0f), ((1050.0f/2.0f)-20.0f), "IBM", 1.0f, red); 
	}
	//m_renderer->SwapBuffers();
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
	if (a.type() == "START")
	{
		if (a.name() == "_LMB")
		{
			m_primaryActionActive = true;
		}

		if(a.name() == "SPACE")
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

		if(a.name() == "_F3")
		{
			m_game->toggleOverlay();
		}
	}
	if(a.type() == "END")
	{
		if(a.name() == "_LMB")
		{
			m_primaryActionActive = false;
		}
	}
	if (a.name() == "ESC")
	{
		glfwSetWindowShouldClose(m_renderer->getWindow(), true);
		m_game->quit();
	}
}


void Scene_test::registerAction(int keycode, const Name aName)
{
	m_actionMap[keycode] = aName;
}


std::map<int, std::string>& Scene_test::getAM()
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