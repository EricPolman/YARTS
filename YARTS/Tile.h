#pragma once
#include "StdAfx.h"

class Tile
{
public:
	enum GroundType {GRASS, STONE, DIRT, ICE};
	Tile(GroundType type);
	~Tile(void);

	void update(const float fDeltaTime);
	void draw(sf::RenderWindow&);

	GroundType m_groundType;
	sf::Sprite m_sprite;
};

