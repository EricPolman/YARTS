#pragma once
#include "StdAfx.h"

class SceneNode
{
public:
	SceneNode(const SceneNode *parent);
	~SceneNode(void);

	const SceneNode *m_parent;
	std::vector<SceneNode*> m_children;
	sf::Vector2f m_relativePosition;
	sf::Vector2f getAbsolutePosition(sf::Vector2f relativePosition) const;
	void move(sf::Vector2f vec);
	void move(float x, float y);
	void update(float fDeltaTime);

	bool m_bIsRootNode;
};

