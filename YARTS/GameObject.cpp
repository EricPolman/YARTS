#include "GameObject.h"

GameObject::GameObject(const SceneNode *parent) : SceneNode(parent)
{
	m_state = IDLE;
	m_bIsSelected = false;
}

GameObject::~GameObject(void)
{
}

void GameObject::update(float fDeltaTime)
{
	if(m_bIsSelected){
		if(Input::getButtonUp(sf::Mouse::Right)){
			m_targetPosition = sf::Vector2f(Input::g_mousePosition.x, Input::g_mousePosition.y);
			m_state = WALKING;
		}
	}
	if(m_state == WALKING){
		setDirection();
		if(getDistance(m_targetPosition) > 10){
			SceneNode::move(m_direction * 200.0f * fDeltaTime);
			m_state = WALKING;
		}else{
			m_state = IDLE;
		}
	}
	AnimatedSprite::update(fDeltaTime);

	setPosition(getAbsolutePosition(m_relativePosition));
}

void GameObject::draw(sf::RenderWindow& window)
{
	AnimatedSprite::draw(window);
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

void GameObject::setDirection(){
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

void GameObject::moveTarget(float dx, float dy){
	m_targetPosition.x += dx;
	m_targetPosition.y += dy;
}

void GameObject::toggleSelection(){
	if(!m_bIsSelected){
		m_bIsSelected = true;
		setColor(sf::Color::Green);
	}else{
		m_bIsSelected = false;
		setColor(sf::Color::White);
	}
}