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
#include "Ui.h"
#include "Powerup.h"
#include "LevelBuilder.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Breakout");
	loadAssets();
	player = new Paddle(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT * 0.95f, sf::Color::White, sf::Color::Transparent);
	ball = new Ball();
	Ui ui;
	levelBuilder.buildLevel(level);

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
				//switch between mouse mode and keyboard mode
				if (event.key.code == sf::Keyboard::S && !isGameOver) {
					mouseMode = !mouseMode;
				}
				//restart game
				if (event.key.code == sf::Keyboard::R && isGameOver) {
					resetGame();
				}
			}
			if (event.type == sf::Event::EventType::MouseButtonPressed && mouseMode && !ball->isActive && !isGameOver) {
				ball->setActive(true);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !mouseMode && !ball->isActive && !isGameOver)
		{
			ball->setActive(true);
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
			player->checkCollision();
			player->draw(window);
			if (bricks.size() <= 0) {
				level++;
				playSound(6);
				ball->reset();
				levelBuilder.buildLevel(level);
			}
			for (int i = 0; i < bricks.size(); i++) {
				bricks.at(i)->draw(window);
			}
			for (int i = 0; i < fixedBricks.size(); i++) {
				fixedBricks.at(i)->draw(window);
			}
			for (int i = 0; i < powerups.size(); i++) {
				powerups.at(i)->update();
				if(powerups.at(i)->checkOutOfRange()){
					powerups.erase(powerups.begin() + i);
				}
				else {
					powerups.at(i)->draw(window);
				}
			}
			for (int i = 0; i < waves.size(); i++) {
				waves.at(i)->update();
				if (waves.at(i)->life <= 0) {
					waves.erase(waves.begin() + i);
				}
				else {
					waves.at(i)->draw(window);
				}
			}
			ball->update();
			ball->draw(window);
		}
		else {
			ui.drawGameOver(window);
		}
		ui.update();
		ui.drawInfo(window);
		window.display();
	}

	return 0;
}
