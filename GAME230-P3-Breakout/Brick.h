#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Brick {
public:
	sf::Vector2f position;
	float width;
	float height;
	sf::RectangleShape shape;
	sf::Color color;

	Brick(float pX, float pY, sf::Color color);
	~Brick();
	void draw(sf::RenderWindow& window);
};