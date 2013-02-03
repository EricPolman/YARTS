#include "stdafx.h"
#include "Game.h"

int main()
{
	sf::RenderWindow Window(sf::VideoMode(800,600,32), "SFML Game");
	Window.setFramerateLimit(60);
	sf::Clock deltaClock;
	Game game;
	float elapsedTime = 0;
	bool bHasFocus = true;


	game.load();
	while (Window.isOpen()) {	
		sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Window.close();
			}

			if(event.type == sf::Event::LostFocus){
				bHasFocus = false;
			}
			if(event.type == sf::Event::GainedFocus){
				bHasFocus = true;
			}
        }
		sf::Time dt = deltaClock.restart();
		float fDeltaTime = dt.asSeconds();
			
		if(bHasFocus){
			elapsedTime += fDeltaTime;
			Window.clear(sf::Color::Black);
			Input::update(fDeltaTime, Window);
			game.update(fDeltaTime);
			game.draw(Window);
			Window.display();
		}
    }
    return 0;
}