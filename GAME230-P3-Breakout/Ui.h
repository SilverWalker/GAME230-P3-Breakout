#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ui {
public:
	sf::Font font;
	sf::Text scoreText;
	sf::Text lifeText;
	sf::Text levelText;
	sf::Text gameOverText;
	sf::Text restartText;

	sf::Texture bgTexture;
	sf::RectangleShape bgShape;

	Ui();
	void update();
	void drawBg(sf::RenderWindow& window);
	void drawInfo(sf::RenderWindow& window);
	void drawGameOver(sf::RenderWindow& window);
};