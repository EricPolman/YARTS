
#include "Tile.h"


Tile::Tile(GroundType type)
{
	m_groundType = type;
	m_sprite.setTexture(*TextureManager::getInstance()->m_Textures["terraintiles"]);
	m_sprite.setTextureRect(sf::IntRect(0, 128 * type, TILE_SIZE, TILE_SIZE));
}

Tile::~Tile(void)
{
}

void Tile::update(float fDeltaTime){
	
}

void Tile::draw(sf::RenderWindow& window){
	window.draw(m_sprite);
}