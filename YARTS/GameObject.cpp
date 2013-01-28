#include "StdAfx.h"
#include "GameObject.h"

sf::Vector2i mousePosition;

GameObject::GameObject(void)
{
}

GameObject::~GameObject(void)
{
}

void GameObject::update(float fDeltaTime)
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
		m_targetPosition = sf::Vector2f(mousePosition.x, mousePosition.y);
		m_direction = m_targetPosition - getPosition();
		if(m_direction.x == 0 && m_direction.y == 0){
			m_direction.y = 1;
		}
		normalizeVector(m_direction);

		float newRot = asinf(m_direction.x) * 180 / PI;
		if(m_direction.y > 0){	
			newRot = 180 - newRot;
		}
		setRotation(newRot);
	}
	if(getDistance(m_targetPosition) > 10){
		move(m_direction * 200.0f * fDeltaTime);
	}
	AnimatedSprite::update(fDeltaTime);
}

void GameObject::draw(sf::RenderWindow& window)
{
	AnimatedSprite::draw(window);
	mousePosition = sf::Mouse::getPosition(window);
}

void GameObject::normalizeVector(sf::Vector2f &vector)
{
	float magnitude = std::sqrtf(vector.x * vector.x + vector.y * vector.y);
	vector.x /= magnitude;
	vector.y /= magnitude;
}

float GameObject::getDistance(sf::Vector2f other)
{
	sf::Vector2f vector = other - getPosition();
	return std::sqrtf(vector.x * vector.x + vector.y * vector.y);
}