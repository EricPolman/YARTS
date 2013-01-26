#pragma once
#include "StdAfx.h"
#include "GameObject.h"

class Scene
{
public:
	Scene(void);
	~Scene(void);

	void update(const float fDeltaTime);
	void draw(sf::RenderWindow&);

	sf::IntRect m_dimensions;
	GameObject *m_currentFocus;
	bool m_bIsFocused;


};

