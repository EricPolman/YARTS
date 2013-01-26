#pragma once
class Game
{
public:
	Game();
	~Game();
	void load();
	void update(const float fDeltaTime);
	void draw(sf::RenderWindow& window);
};

