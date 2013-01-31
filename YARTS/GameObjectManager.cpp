#include "GameObjectManager.h"

GameObjectManager::GameObjectManager(void)
{
}

GameObjectManager::~GameObjectManager(void)
{
	instanceFlag = false;
	for(std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i)
	{
		m_gameObjects.erase(i);
	}
}

bool GameObjectManager::instanceFlag = false;
GameObjectManager* GameObjectManager::single = NULL;
GameObjectManager* GameObjectManager::getInstance()
{
    if(!instanceFlag)
    {
        single = new GameObjectManager();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void GameObjectManager::load(){

}

void GameObjectManager::update(const float fDeltaTime){
	for(std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i)
	{
		(*i)->update(fDeltaTime);
	}
}

void GameObjectManager::draw(sf::RenderWindow& window){
	for(std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i)
	{
		(*i)->draw(window);
	}
}

void GameObjectManager::moveTargets(float dx, float dy){
	for(std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i)
	{
		(*i)->moveTarget(dx, dy);
	}
}