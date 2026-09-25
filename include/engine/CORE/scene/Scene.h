#ifndef SCENE_H
#define SCENE_H


#include <string>
#include <map>
#include <memory>

#include "ICommand.h"



class Engine;
class Renderer;


class Scene 
{
private:
	int m_frame = 0; //may keep may remove?
	bool m_paused = false;
	std::map<int, Name> m_actionMap;
	Renderer* m_renderer = nullptr;
	Engine* m_engine = nullptr;
public:
	//GameEngine* m_game = nullptr;
	//assetMan* m_assetMan = nullptr; //just here as a reminder, remove when comfortable. 
	//Palette* m_palette; //might bring this back
	//EntityMemoryPool m_pool; //might take a slightly different approch idk. 
	//EntityFactory m_factory; //will probably end up replacing and reworking
    //EntityMan m_entityManager; //will probably end up replacing and reworking
    //size_t m_maxEntities; //change to pbv structure? idk we will figure it out. 

	Scene(Engine* game, Renderer* renderer)
        : m_engine(game), m_renderer(renderer)
    {}
    virtual void init() = 0;
	virtual ~Scene() = default;
	//virtual void init(GameEngine* game) = 0;
	virtual void update() = 0;
	virtual void sDoAction() = 0;
	virtual void sRender() = 0;
	//virtual void simulate(int i) = 0;
	virtual void doAction(const Action& c) = 0;
	virtual void registerAction(int keycode, const Name aName) = 0;
	virtual std::map<int, Name>& getAM() = 0;
};
#endif

//game->changeScene<Scene_Play>("play", LevelPath);