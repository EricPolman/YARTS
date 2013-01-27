#pragma once
#include "Tile.h"

class Terrain
{
public:
	Terrain(void);
	~Terrain(void);

	void update(const float fDeltaTime);
	void draw(sf::RenderWindow&);
	void move(float x, float y);

	Tile *grid[MAX_MAP_WIDTH][MAX_MAP_HEIGHT];
};