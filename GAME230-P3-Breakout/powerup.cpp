#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Powerup.h"

Powerup::Powerup(float pX, float pY, int upType)
{
	this->position.x = pX;
	this->position.y = pY;
	this->speed = 200.0f;
	this->size = 30;
	this->upType = upType;	//0: Larger paddle  1: Smaller paddle  2:Slower ball  3: Faster ball  4:Extra points  5: Safety net
	this->color = powerupColors[upType];
	this->outlineColor = powerupColors[upType];
}

Powerup::~Powerup()
{
	switch (this->upType) {
		case 0:
			player->width = 150;
			break;
		case 1:
			player->width = 50;
			break;
		case 2:
			if (ball->speed > 300.0f) { ball->speed -= 200.0f; }
			break;
		case 3:
			ball->speed += 200.0f;
			break;
		case 4:
			score += 500;
			break;
	}
}

void Powerup::draw(sf::RenderWindow& window)
{
	shape.setSize({ this->size, this->size });
	shape.setOrigin(this->size / 2, this->size / 2);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(this->color);
	shape.setTexture(&powerupTextures[this->upType]);
	//shape.setOutlineColor(this->outlineColor);
	//shape.setOutlineThickness(3);
	window.draw(shape);
}

void Powerup::update() {
	this->position.y += this->speed * dt.asSeconds();
}

bool Powerup::checkOutOfRange() {
	return this->position.y - this->size / 2 > WINDOW_HEIGHT;
}