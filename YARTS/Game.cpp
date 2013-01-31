#include "StdAfx.h"
#include "Game.h"

Game::Game(void){
}

Game::~Game(void){
}

void Game::load(){
	m_scene = new Scene();
}

void Game::update(float fDeltaTime){
	m_scene->update(fDeltaTime);
}

void Game::draw(sf::RenderWindow& window){
	m_scene->draw(window);
}