#pragma once
#include "StdAfx.h"
#include "GameObject.h"
#include "Terrain.h"
#include "CameraMan.h"

class Scene
{
public:
	Scene(void);
	~Scene(void);

	void update(const float fDeltaTime);
	void draw(sf::RenderWindow&);
	void clampCamera();

	sf::IntRect m_dimensions;
	GameObject *m_currentFocus;
	bool m_bIsFocused;

	Terrain *m_terrain;
	CameraMan m_cameraMan;
};

