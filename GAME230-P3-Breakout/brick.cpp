#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Brick.h"

Brick::Brick(float pX, float pY, sf::Color color)
{
	this->position.x = pX;
	this->position.y = pY;
	this->width = 100;
	this->height = 40;
	this->color = color;
}

void Brick::draw(sf::RenderWindow& window)
{
	shape.setSize({ this->width, this->height });
	shape.setOrigin(this->width / 2, this->height / 2);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(this->color);
	window.draw(shape);
}