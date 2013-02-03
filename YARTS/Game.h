#pragma once
#include "Scene.h"

class Game
{
public:
	Game();
	~Game();
	void load();
	void update(const float fDeltaTime);
	void updateMouse(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	Scene *m_scene;
};

