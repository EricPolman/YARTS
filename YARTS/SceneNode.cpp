#include "SceneNode.h"


SceneNode::SceneNode(const SceneNode *parent){
	m_relativePosition = sf::Vector2f(10,10);
	m_parent = parent;
	if(parent == NULL){
		m_bIsRootNode = true;
	}else{
		m_bIsRootNode = false;
	}
}

SceneNode::~SceneNode(void){
}

sf::Vector2f SceneNode::getAbsolutePosition(sf::Vector2f relativePosition) const{
	if(!m_bIsRootNode){
		return relativePosition + m_parent->getAbsolutePosition(relativePosition);
	}else{
		return m_relativePosition;
	}
}

void SceneNode::move(sf::Vector2f vec){
	m_relativePosition += vec;
}

void SceneNode::move(float x, float y){
	m_relativePosition += sf::Vector2f(x, y);
}

void SceneNode::update(float fDeltaTime){

}