#pragma once
#include "stdafx.h"
#include <map>

class TextureManager
{
public:
	~TextureManager(void);
	static TextureManager* getInstance(void);
	void loadTexture(std::string path, std::string name);
	std::map<std::string, sf::Texture*> m_Textures;

private:
	static bool instanceFlag;
	static TextureManager *single;
	TextureManager(void);
};
