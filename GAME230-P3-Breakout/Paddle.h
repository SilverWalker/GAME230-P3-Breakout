#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ball;

class Paddle {
public:
	sf::Vector2f position;
	float speed;
	float width;
	float height;
	sf::RectangleShape shape;
	sf::Color color;
	sf::Color outlineColor;

	Paddle(float pX, float pY, sf::Color color, sf::Color outlineColor);
	void draw(sf::RenderWindow& window);
	void moveLeft();
	void moveRight();
	void reset();
};