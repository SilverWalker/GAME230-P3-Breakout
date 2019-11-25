#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Powerup {
public:
	sf::Vector2f position;
	float speed;
	float size;
	sf::RectangleShape shape;
	sf::Color color;
	sf::Color outlineColor;
	int upType;

	Powerup(float pX, float pY, int upType);
	~Powerup();
	void draw(sf::RenderWindow& window);
	void update();
	bool checkOutOfRange();
};