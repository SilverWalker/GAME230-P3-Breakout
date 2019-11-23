#include <iostream>
#include <string>
#include "Setting.h"
#include "Ui.h"

Ui::Ui()
{
	this->font.loadFromFile("asset/font/JustMyType-KePl.ttf");
	//this->bgTexture.loadFromFile("bg.png");
	
	/*this->bgShape.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	this->bgShape.setPosition(0, 0);
	this->bgShape.setTexture(&this->bgTexture);*/

	this->scoreText.setFont(this->font);
	this->scoreText.setString("Score: " + std::to_string(score));
	this->scoreText.setCharacterSize(WINDOW_WIDTH / 36);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.1, WINDOW_HEIGHT * 0.01));

	this->lifeText.setFont(this->font);
	this->lifeText.setString("Life: " + std::to_string(life));
	this->lifeText.setCharacterSize(WINDOW_WIDTH / 36);
	this->lifeText.setFillColor(sf::Color::White);
	this->lifeText.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.9, WINDOW_HEIGHT * 0.01));

	this->gameOverText.setFont(this->font);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setCharacterSize(WINDOW_WIDTH / 12);
	this->gameOverText.setFillColor(sf::Color::White);
	sf::FloatRect gameOverBounds = this->gameOverText.getLocalBounds();
	this->gameOverText.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.5 - gameOverBounds.width / 2, WINDOW_HEIGHT * 0.4));

	this->restartText.setFont(this->font);
	this->restartText.setString("Press spacebar to restart game");
	this->restartText.setCharacterSize(WINDOW_WIDTH / 24);
	this->restartText.setFillColor(sf::Color::White);
	sf::FloatRect restartBounds = this->restartText.getLocalBounds();
	this->restartText.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.5 - restartBounds.width / 2, WINDOW_HEIGHT * 0.55));
}

void Ui::update()
{
	this->scoreText.setString("Score: " + std::to_string(score));
	this->lifeText.setString("Life: " + std::to_string(life));
}

void Ui::drawBg(sf::RenderWindow& window)
{
	window.draw(this->bgShape);
}

void Ui::drawInfo(sf::RenderWindow& window)
{
	window.draw(this->scoreText);
	window.draw(this->lifeText);
}

void Ui::drawGameOver(sf::RenderWindow& window)
{
	window.draw(this->gameOverText);
	window.draw(this->restartText);
}