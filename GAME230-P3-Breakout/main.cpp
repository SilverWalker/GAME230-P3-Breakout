#include <iostream>
#include <stdlib.h> 
#include <time.h> 

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "Setting.h"
#include "Paddle.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Breakout");

	player = new Paddle(WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.95, sf::Color::White, sf::Color::Red);
	ball = new Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	
	for (int i = 0; i < 100; i++) {
		bricks.push_back(new Brick((i % 10) * 100 + 50, int(i / 10) * 40 + 20, sf::Color(i * 5, i * 5, 250)));
	}

	srand(time(NULL));
	while (window.isOpen())
	{
		dt = deltaClock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::EventType::KeyPressed) {
				//switch between player mode and AI mode
				if (event.key.code == sf::Keyboard::S && !isGameOver) {
					mouseMode = !mouseMode;
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !mouseMode)
		{
			player->moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !mouseMode)
		{
			player->moveRight();
		}
		if (mouseMode) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (mousePos.x - player->width / 2 < 0) {
				player->position.x = player->width / 2;
			} else if (mousePos.x + player->width / 2 > WINDOW_WIDTH) {
				player->position.x = WINDOW_WIDTH - player->width / 2; 
			} else { 
				player->position.x = mousePos.x; 
			}
		}
		window.clear();
		if (!isGameOver) {
			frameCount++;
			player->draw(window);
			for (int i = 0; i < bricks.size(); i++) {
				bricks.at(i)->draw(window);
			}
			ball->update();
			ball->draw(window);
		}
		window.display();
	}

	return 0;
}
