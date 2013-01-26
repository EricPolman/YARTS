#include "StdAfx.h"

TextureManager::TextureManager(void)
{
}

TextureManager::~TextureManager(void)
{
	instanceFlag = false;
	for(std::map<std::string, sf::Texture*>::iterator i = m_Textures.begin(); i != m_Textures.end(); ++i)
	{
		m_Textures.erase(i);
	}
}

bool TextureManager::instanceFlag = false;
TextureManager* TextureManager::single = NULL;
TextureManager* TextureManager::getInstance()
{
    if(! instanceFlag)
    {
        single = new TextureManager();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}


void TextureManager::loadTexture(std::string path, std::string name)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	m_Textures[name] = texture;
}