#pragma once
#include "StdAfx.h"

class CameraMan
{
public:
	CameraMan(void);
	~CameraMan(void);
	
	void update(const float fDeltaTime);

	sf::Vector2f m_position;
};

