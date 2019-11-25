#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Paddle.h"

Paddle::Paddle(float pX, float pY, sf::Color color, sf::Color outlineColor)
{
	this->position.x = pX;
	this->position.y = pY;
	this->speed = 800.0f;
	this->width = 100;
	this->height = 20;
	this->color = color;
	this->outlineColor = outlineColor;
}

void Paddle::draw(sf::RenderWindow& window)
{
	shape.setSize({ this->width, this->height });
	shape.setOrigin(this->width / 2, this->height / 2);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(this->color);
	shape.setOutlineColor(this->outlineColor);
	shape.setOutlineThickness(3);
	window.draw(shape);
}

void Paddle::moveLeft()
{
	if (this->position.x - this->width / 2 > 0) {
		this->position.x -= this->speed * dt.asSeconds();
	}
}

void Paddle::moveRight()
{
	if (this->position.x + this->width / 2 < WINDOW_WIDTH) {
		this->position.x += this->speed * dt.asSeconds();
	}
}

void Paddle::reset() {
	this->speed = 800.0f;
	this->width = 100;
	this->height = 20;
}

void Paddle::checkCollision() {
	//powerup
	for (int i = 0; i < powerups.size(); i++) {
		if (this->position.x + this->width / 2 > powerups.at(i)->position.x - powerups.at(i)->size / 2 &&
			this->position.x - this->width / 2 < powerups.at(i)->position.x + powerups.at(i)->size / 2 &&
			this->position.y + this->height / 2 > powerups.at(i)->position.y - powerups.at(i)->size / 2 &&
			this->position.y - this->height / 2 < powerups.at(i)->position.y + powerups.at(i)->size / 2) {
			delete powerups[i];
			powerups.erase(powerups.begin() + i);
		}
	}
}