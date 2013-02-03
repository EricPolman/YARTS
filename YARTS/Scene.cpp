#include "Scene.h"

Scene::Scene(void){
	m_rootNode = new SceneNode(NULL);

	m_terrain = new Terrain();
	m_bIsFocused = false;
	m_cameraMan.m_position.x = MAX_MAP_WIDTH * TILE_SIZE * 0.5f - TILE_SIZE;
	m_cameraMan.m_position.y = MAX_MAP_HEIGHT * TILE_SIZE * 0.5f - TILE_SIZE;

	TextureManager::getInstance()->loadTexture("Data/Images/sheet1.png", "sfmlgame");
	GameObject *gameObject = new GameObject(m_rootNode);
	gameObject->load("sfmlgame", true, 128, 128, 4, 4);
	gameObject->SceneNode::move(100,100);
	GameObjectManager::getInstance()->m_gameObjects.push_back(gameObject);

	GameObject *gameObject2 = new GameObject(m_rootNode);
	gameObject2->load("sfmlgame", true, 128, 128, 4, 4);
	GameObjectManager::getInstance()->m_gameObjects.push_back(gameObject2);

}

Scene::~Scene(void){
	delete m_terrain;
}

void Scene::update(float fDeltaTime){
	m_terrain->update(fDeltaTime);
	GameObjectManager::getInstance()->update(fDeltaTime);

	if(!m_bIsFocused){
		m_cameraMan.update(fDeltaTime);
		
		m_terrain->move(-m_cameraMan.m_position.x, -m_cameraMan.m_position.y);
		m_rootNode->move(-m_cameraMan.m_position.x, -m_cameraMan.m_position.y);
		GameObjectManager::getInstance()->moveTargets(-m_cameraMan.m_position.x, -m_cameraMan.m_position.y);

		m_cameraMan.m_position.x = m_cameraMan.m_position.y = 0;	
	}
	clampCamera();

	if(Input::getButtonDown(sf::Mouse::Left)){
		for(int i = 0; i < GameObjectManager::getInstance()->m_gameObjects.size(); i++){
			GameObject &go = *GameObjectManager::getInstance()->m_gameObjects[i];
			if(Input::g_mousePosition.x > go.getPosition().x - go.getOrigin().x &&
			   Input::g_mousePosition.x < go.getPosition().x + go.getOrigin().x &&
			   Input::g_mousePosition.y > go.getPosition().y - go.getOrigin().y &&
			   Input::g_mousePosition.y < go.getPosition().y + go.getOrigin().y)
			{				
				GameObjectManager::getInstance()->m_gameObjects[i]->toggleSelection();
			}
			else if(GameObjectManager::getInstance()->m_gameObjects[i]->m_bIsSelected){
				GameObjectManager::getInstance()->m_gameObjects[i]->toggleSelection();	
			}
		}
	}
}

void Scene::draw(sf::RenderWindow& window){
	m_terrain->draw(window);
	GameObjectManager::getInstance()->draw(window);
}

void Scene::clampCamera(){
	float dx = 0, dy = 0;
	if(m_terrain->grid[0][0]->m_sprite.getPosition().x > 0)
	{
		dx = -m_terrain->grid[0][0]->m_sprite.getPosition().x;
	}
	else if(m_terrain->grid[MAX_MAP_WIDTH - 1][0]->m_sprite.getPosition().x + TILE_SIZE < WINDOW_WIDTH)
	{
		dx = WINDOW_WIDTH - m_terrain->grid[MAX_MAP_WIDTH - 1][0]->m_sprite.getPosition().x - TILE_SIZE;
	}
	if(m_terrain->grid[0][0]->m_sprite.getPosition().y > 0)
	{
		dy = -m_terrain->grid[0][0]->m_sprite.getPosition().y;
	}
	else if(m_terrain->grid[0][MAX_MAP_HEIGHT - 1]->m_sprite.getPosition().y + TILE_SIZE < WINDOW_HEIGHT)
	{
		dy = WINDOW_HEIGHT - m_terrain->grid[0][MAX_MAP_HEIGHT - 1]->m_sprite.getPosition().y - TILE_SIZE;
	}

	m_terrain->move(dx, dy);
	m_rootNode->move(dx, dy);
	GameObjectManager::getInstance()->moveTargets(dx, dy);
}