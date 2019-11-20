#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ball {
public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	float speed;
	float angle;
	float radius;
	sf::CircleShape shape;
	sf::Color color;
	std::vector<sf::Vector2f> trails;
	sf::CircleShape trailShape;

	Ball(float pX, float pY);
	void update();
	void draw(sf::RenderWindow& window);
	void checkCollision();
};