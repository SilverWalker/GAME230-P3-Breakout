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
	this->isCircle = true;
}

Wave::Wave(float pX, float pY, float width, float height, sf::Color color)
{
	this->position.x = pX;
	this->position.y = pY;
	this->color = color;
	this->life = 90;
	this->width = width;
	this->height = height;
	this->isCircle = false;
}

void Wave::update() 
{
	this->life--;
	if (this->isCircle) {
		this->radius = 100.0f - this->life;
	}
	else {
		this->width += this->width * 0.00005f * (100 - this->life);
		this->height += this->height * 0.00005f * (100 - this->life);
	}
}

void Wave::draw(sf::RenderWindow& window)
{
	if (this->isCircle) {
		circleWave.setRadius({ this->radius });
		circleWave.setOrigin(this->radius, this->radius);
		circleWave.setPosition(this->position.x, this->position.y);
		circleWave.setFillColor(sf::Color::Transparent);
		circleWave.setOutlineColor(this->color);
		circleWave.setOutlineThickness(3);
		window.draw(circleWave);
	}
	else {
		rectWave.setSize({ this->width, this->height });
		rectWave.setOrigin(this->width / 2, this->height / 2);
		rectWave.setPosition(this->position.x, this->position.y);
		rectWave.setFillColor(sf::Color::Transparent);
		rectWave.setOutlineColor(this->color);
		rectWave.setOutlineThickness(3);
		window.draw(rectWave);	
	}
}