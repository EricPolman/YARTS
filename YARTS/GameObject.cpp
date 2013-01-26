#include "StdAfx.h"
#include "GameObject.h"

GameObject::GameObject(void)
{
}

GameObject::~GameObject(void)
{
}

void GameObject::update(float fDeltaTime)
{
	rotate(fDeltaTime * 360);
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		move(fDeltaTime * 400,0);
	}
	if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
		move(fDeltaTime * -400,0);
	}

	AnimatedSprite::update(fDeltaTime);
}

void GameObject::draw(sf::RenderWindow& window)
{
	AnimatedSprite::draw(window);
}