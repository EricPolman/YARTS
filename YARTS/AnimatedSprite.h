#pragma once
#include "stdafx.h"

class AnimatedSprite :
	public sf::Sprite
{
public:
	AnimatedSprite(void);
	virtual ~AnimatedSprite(void);

	virtual void load(std::string textureName, bool bIsSpritesheet = false, 
		int framesizeX = 0, int framesizeY = 0, int framesX = 0, int framesY = 0);
	virtual void update(const float fDeltaTime);
	virtual void draw(sf::RenderWindow&);

	bool m_bIsVisible;
	bool m_bIsAnimated;
	bool m_bIsLooping;

	bool m_bNextFrame;
	float m_fAnimationSpeed;
	float m_fAnimationTimer;
	
	sf::Vector2i m_frames;
	sf::Vector2i m_frameSize;
	
	sf::Vector2i m_currentFrame;
	std::string m_sCurrentAnimation;

	struct AnimationData {sf::Vector2i begin;sf::Vector2i end;};
	std::map<std::string, AnimationData> m_animations;

	void addAnimation(std::string name, sf::Vector2i beginFrame, sf::Vector2i endFrame);
	void playAnimation(std::string name, bool loop = false);

private:
	void animate();
	inline void setFrame(sf::Vector2i frame);
};

