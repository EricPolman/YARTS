#include "Input.h"

sf::Vector2f Input::g_mousePosition = sf::Vector2f(0,0);
bool Input::oldMouseState[sf::Mouse::ButtonCount];
bool Input::currentMouseState[sf::Mouse::ButtonCount];

Input::Input(void)
{
	for(int i = 0; i < sf::Mouse::ButtonCount; i++){
		oldMouseState[i] = currentMouseState[i] = false;
	}
}


Input::~Input(void)
{
}

void Input::update(float fDeltaTime, sf::RenderWindow &window){
	for(int i = 0; i < sf::Mouse::ButtonCount; i++){
		oldMouseState[i] = currentMouseState[i];
	}
	for(int i = 0; i < sf::Keyboard::KeyCount; i++){
		oldKeyboardState[i] = currentKeyboardState[i];
	}

	g_mousePosition = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

	for(int i = 0; i < sf::Mouse::ButtonCount; i++){
		currentMouseState[i] = sf::Mouse::isButtonPressed((sf::Mouse::Button)i);
	}
	for(int i = 0; i < sf::Keyboard::KeyCount; i++){
		currentKeyboardState[i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
	}
}

bool Input::getButtonDown(sf::Mouse::Button button){
	if(currentMouseState[(int)button] && !oldMouseState[(int)button]){
		return true;
	}
	return false;
}

bool Input::getButtonUp(sf::Mouse::Button button){
	if(!currentMouseState[(int)button] && oldMouseState[(int)button]){
		return true;
	}
	return false;
}

bool Input::getButtonPressed(sf::Mouse::Button button){
	if(currentMouseState[(int)button]){
		return true;
	}
	return false;
}

bool Input::getKeyDown(sf::Keyboard::Key key){
	if(currentKeyboardState[(int)key] && !oldKeyboardState[(int)key]){
		return true;
	}
	return false;
}

bool Input::getKeyUp(sf::Keyboard::Key key){
	if(!currentKeyboardState[(int)key] && oldKeyboardState[(int)key]){
		return true;
	}
	return false;
}

bool Input::getKeyPressed(sf::Keyboard::Key key){
	if(currentKeyboardState[(int)key]){
		return true;
	}
	return false;
}