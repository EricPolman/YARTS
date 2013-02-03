#pragma once
#include "SFML\Graphics.hpp"

class Input
{
public:
	Input(void);
	~Input(void);

	static void update(float fDeltaTime, sf::RenderWindow &window);
	static sf::Vector2f g_mousePosition;

	static bool getButtonPressed(sf::Mouse::Button button);
	static bool getButtonDown(sf::Mouse::Button button);
	static bool getButtonUp(sf::Mouse::Button button);

	static bool getKeyPressed(sf::Keyboard::Key key);
	static bool getKeyDown(sf::Keyboard::Key key);
	static bool getKeyUp(sf::Keyboard::Key key);
private:
	static bool oldMouseState[sf::Mouse::ButtonCount];
	static bool currentMouseState[sf::Mouse::ButtonCount];
	static bool oldKeyboardState[sf::Keyboard::KeyCount];
	static bool currentKeyboardState[sf::Keyboard::KeyCount];
};

