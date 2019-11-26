#include <iostream>
#include "Setting.h"
#include "Wave.h"

Wave::Wave(float pX, float pY, sf::Color color)
{
	this->position.x = pX;
	this->position.y = pY;
	this->color = color;
	this->life = 90;
	this->radius = 100.0f - this->life;
}

void Wave::update() 
{
	this->life--;
	this->radius = 100.0f - this->life;
}

void Wave::draw(sf::RenderWindow& window)
{
	shape.setRadius({ this->radius });
	shape.setOrigin(this->radius, this->radius);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(this->color);
	shape.setOutlineThickness(3);
	window.draw(shape);
}