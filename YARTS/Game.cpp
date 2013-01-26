#include "StdAfx.h"
#include "Game.h"
#include "GameObject.h"

GameObject *gameObject;

Game::Game(void)
{
}

Game::~Game(void)
{
}

void Game::load(){
	TextureManager::getInstance()->loadTexture("Data/Images/sheet1.png", "sfmlgame");
	gameObject = new GameObject();
	gameObject->load("sfmlgame", true, 128, 128, 4, 4);
	gameObject->move(400,300);
}

void Game::update(float fDeltaTime){
	gameObject->update(fDeltaTime);
}

void Game::draw(sf::RenderWindow& window){
	gameObject->draw(window);
}