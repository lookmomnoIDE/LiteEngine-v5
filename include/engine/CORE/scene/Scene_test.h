#ifndef SCENE_TEST_H
#define SCENE_TEST_H


//#include <cmath>
//#include <algorithm>
#include <iostream>

#include "Scene.h"
#include "Engine.h"
#include "renderer.h"


class Scene_test : public Scene
{
	std::string m_level = "play";
	double m_x, m_y, m_currentTime, m_elapsedTime, m_dt;
	bool m_primaryActionActive = false;
	unsigned int currentEntities = 0;
	unsigned int m_numQuads = 0;
	unsigned int m_frameCounter = 0;


public:
	Scene_test(Engine* game, Renderer* renderer, size_t maxEntities);
	~Scene_test(){}
	void init() override;
	void update() override;
	//void sAnimation();
	//void sEnemySpawner(); 
	//void sCollision();
	void sRender() override;
	void sGUI();
	bool isPaused();
	void doAction(const Action& a) override;
	void registerAction(int keycode, const Name aName) override;
	void sDoAction() override;
	std::map<int, Name>& getAM() override;

};


#endif