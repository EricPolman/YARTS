#include "StdAfx.h"
#include "Terrain.h"


Terrain::Terrain(){
	TextureManager::getInstance()->loadTexture("Data/Images/terrain.png", "terraintiles");
	for(int x = 0; x < MAX_MAP_WIDTH; x++){
		for(int y = 0; y < MAX_MAP_HEIGHT; y++){
			grid[x][y] = new Tile((Tile::GroundType)(std::rand() % GROUND_TYPES));
			grid[x][y]->m_sprite.move(x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

Terrain::~Terrain(void){
	for(int x = 0; x < MAX_MAP_WIDTH; x++){
		for(int y = 0; y < MAX_MAP_HEIGHT; y++){
			delete grid[x][y];
		}
	}
}

void Terrain::update(float fDeltaTime){
	for(int x = 0; x < MAX_MAP_WIDTH; x++){
		for(int y = 0; y < MAX_MAP_HEIGHT; y++){
			grid[x][y]->update(fDeltaTime);
		}
	}
}

void Terrain::draw(sf::RenderWindow& window){
	for(int x = 0; x < MAX_MAP_WIDTH; x++){
		for(int y = 0; y < MAX_MAP_HEIGHT; y++){
			sf::Vector2f position = grid[x][y]->m_sprite.getPosition();
			if(position.x + TILE_SIZE < -1 ||
			   position.y + TILE_SIZE < -1 ||
			   position.x > WINDOW_WIDTH + 1 ||
			   position.y > WINDOW_HEIGHT + 1){
				continue;
			}
			grid[x][y]->draw(window);
		}
	}
}

void Terrain::move(float dx, float dy)
{
	for(int x = 0; x < MAX_MAP_WIDTH; x++){
		for(int y = 0; y < MAX_MAP_HEIGHT; y++){
			grid[x][y]->m_sprite.move(dx,dy);
		}
	}
}