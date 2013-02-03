#pragma once
#include "AnimatedSprite.h"
#include "SceneNode.h"

class GameObject :
	public SceneNode,
	public AnimatedSprite
{
public:
	virtual ~GameObject(void);
	GameObject(const SceneNode*parent);
	
	virtual void update(const float fDeltaTime);
	virtual void draw(sf::RenderWindow&);

	sf::Vector2f m_targetPosition;
	sf::Vector2f m_direction;

	void normalizeVector(sf::Vector2f &vector);
	float getDistance(sf::Vector2f other);
	void setDirection();
	void moveTarget(float dx, float dy);
	enum State{IDLE, WALKING};
	State m_state;

	bool m_bIsSelected;
	void toggleSelection();
};

