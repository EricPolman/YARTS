#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(void)
{
	m_bIsVisible = true;
	m_bIsAnimated = false;
	m_bNextFrame = false;
	m_bIsLooping = false;
	m_fAnimationSpeed = 1;
	m_fAnimationTimer = 0;
}

AnimatedSprite::~AnimatedSprite(void)
{
}

void AnimatedSprite::load(std::string textureName, bool bIsSpritesheet, 
	int framesizeX, int framesizeY, int framesX, int framesY)
{
	setTexture(*TextureManager::getInstance()->m_Textures[textureName]);

	if(bIsSpritesheet){
		m_frames.x = framesX;
		m_frames.y = framesY;
		m_frameSize.x = framesizeX;
		m_frameSize.y = framesizeY;

		addAnimation("idle", sf::Vector2i(0,0), sf::Vector2i(3,3));

		playAnimation("idle", true);
		m_bIsAnimated = true;
	}
	setOrigin(getTextureRect().width / 2, getTextureRect().height / 2);
}

void AnimatedSprite::update(float fDeltaTime){
	if(m_bIsVisible){
		if(m_bIsAnimated){
			m_fAnimationTimer += fDeltaTime;

			if(m_fAnimationTimer > 1 / m_fAnimationSpeed / 4){
				m_fAnimationTimer = 0;
				animate();
			}
		}
	}
}

void AnimatedSprite::draw(sf::RenderWindow& window){
	if(m_bIsVisible){
		window.draw(*this);
	}
}

void AnimatedSprite::playAnimation(std::string name, bool loop){
	m_sCurrentAnimation = name;
	m_bIsLooping = loop;
	setFrame(m_animations[m_sCurrentAnimation].begin);
}

void AnimatedSprite::addAnimation(std::string name, sf::Vector2i beginFrame, sf::Vector2i endFrame){
	AnimationData data;
	data.begin = beginFrame;
	data.end = endFrame;
	m_animations[name] = data;
}

void AnimatedSprite::setFrame(sf::Vector2i frame){
	setTextureRect(
		sf::IntRect(sf::Vector2i(frame.x * m_frameSize.x,frame.y * m_frameSize.y), 
		m_frameSize)
	);
}

void AnimatedSprite::animate(){
	AnimationData data = m_animations[m_sCurrentAnimation];
	if(m_currentFrame.y == data.end.y && m_currentFrame.x == data.end.x){	
		if(m_bIsLooping){
			m_currentFrame = data.begin;
		}
		else{			
			m_currentFrame = sf::Vector2i(0,0);
			m_sCurrentAnimation = "idle";
		}
	}
	else{
		m_currentFrame.x++;
		if(m_currentFrame.x >= m_frames.x){
			m_currentFrame.x = 0;
			m_currentFrame.y++;
		}
	}
	setFrame(m_currentFrame);
}