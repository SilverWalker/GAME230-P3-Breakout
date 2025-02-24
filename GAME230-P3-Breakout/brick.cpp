#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Brick.h"

Brick::Brick(float pX, float pY, int colorId, int life)
{
	this->position.x = pX;
	this->position.y = pY;
	this->width = 100;
	this->height = 40;
	this->color = brickColors[colorId];
	this->life = life;
}

Brick::~Brick() {
	//spawn powerup
	int chance = rand() % 100;
	if (chance < 20) {
		int type = rand() % 5;
		powerups.push_back(new Powerup(this->position.x, this->position.y, type));
	}
}

void Brick::draw(sf::RenderWindow& window)
{
	shape.setSize({ this->width, this->height });
	shape.setOrigin(this->width / 2, this->height / 2);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(this->color);
	if (this->life < 0) {
		shape.setTexture(&brickFixedTexture);
	}
	else if(this->life > 1){
		shape.setTexture(&brick2Texture);
	}
	else {
		shape.setTexture(&brickTexture);
	}
	window.draw(shape);
}