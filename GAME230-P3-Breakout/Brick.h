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
	int life;

	Brick(float pX, float pY, int colorId, int life);
	~Brick();
	void draw(sf::RenderWindow& window);
};