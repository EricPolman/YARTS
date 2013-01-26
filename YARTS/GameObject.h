#pragma once
#include "AnimatedSprite.h"

class GameObject :
	public AnimatedSprite
{
public:
	GameObject(void);
	virtual ~GameObject(void);

	virtual void update(const float fDeltaTime);
	virtual void draw(sf::RenderWindow&);
};