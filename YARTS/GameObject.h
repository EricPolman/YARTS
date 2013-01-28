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

	sf::Vector2f m_targetPosition;
	sf::Vector2f m_direction;

	void normalizeVector(sf::Vector2f &vector);
	float getDistance(sf::Vector2f other);
};