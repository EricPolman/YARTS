#pragma once
#include "GameObject.h"

class GameObjectManager
{
public:
	~GameObjectManager(void);
	static GameObjectManager* getInstance(void);
	std::vector<GameObject*> m_gameObjects;
	void load();
	void update(const float fDeltaTime);
	void draw(sf::RenderWindow& window);
	void moveTargets(float dx, float dy);
private:
	static bool instanceFlag;
	static GameObjectManager *single;
	GameObjectManager(void);
};

