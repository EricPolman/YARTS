#include "CameraMan.h"

CameraMan::CameraMan(void){
}

CameraMan::~CameraMan(void){
}

void CameraMan::update(float fDeltaTime){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		m_position.x -= CAMERA_SPEED * fDeltaTime;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		m_position.x += CAMERA_SPEED * fDeltaTime;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		m_position.y -= CAMERA_SPEED * fDeltaTime;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		m_position.y += CAMERA_SPEED * fDeltaTime;
	}
}