#include "Scene.h"


Scene::Scene(void){
	m_terrain = new Terrain();
	m_bIsFocused = false;
	m_cameraMan.m_position.x = MAX_MAP_WIDTH * TILE_SIZE * 0.5f - TILE_SIZE;
	m_cameraMan.m_position.y = MAX_MAP_HEIGHT * TILE_SIZE * 0.5f - TILE_SIZE;
}

Scene::~Scene(void){
	delete m_terrain;
}

void Scene::update(float fDeltaTime){
	m_terrain->update(fDeltaTime);
	if(!m_bIsFocused){
		m_cameraMan.update(fDeltaTime);
		
		m_terrain->move(-m_cameraMan.m_position.x, -m_cameraMan.m_position.y);
		m_cameraMan.m_position.x = m_cameraMan.m_position.y = 0;	
	}

	clampCamera();
}

void Scene::draw(sf::RenderWindow& window){
	m_terrain->draw(window);
}

void Scene::clampCamera(){
	float dx = 0, dy = 0;
	if(m_terrain->grid[0][0]->m_sprite.getPosition().x > 0){
		dx = -m_terrain->grid[0][0]->m_sprite.getPosition().x;
	}
	else if(m_terrain->grid[MAX_MAP_WIDTH - 1][0]->m_sprite.getPosition().x + TILE_SIZE < WINDOW_WIDTH){
		dx = WINDOW_WIDTH - m_terrain->grid[MAX_MAP_WIDTH - 1][0]->m_sprite.getPosition().x - TILE_SIZE;
	}
	if(m_terrain->grid[0][0]->m_sprite.getPosition().y > 0){
		dy = -m_terrain->grid[0][0]->m_sprite.getPosition().y;
	}
	else if(m_terrain->grid[0][MAX_MAP_HEIGHT - 1]->m_sprite.getPosition().y + TILE_SIZE < WINDOW_HEIGHT){
		dy = WINDOW_HEIGHT - m_terrain->grid[0][MAX_MAP_HEIGHT - 1]->m_sprite.getPosition().y - TILE_SIZE;
	}
	m_terrain->move(dx, dy);
}