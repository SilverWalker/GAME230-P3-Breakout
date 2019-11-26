#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Wave {
public:
	sf::Vector2f position;
	float radius;
	float width;
	float height;
	sf::CircleShape circleWave;
	sf::RectangleShape rectWave;
	sf::Color color;
	int life;
	bool isCircle;

	Wave(float pX, float pY, sf::Color color);
	Wave(float pX, float pY, float width, float height, sf::Color color);
	void update();
	void draw(sf::RenderWindow& window);
};