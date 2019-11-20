#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Ball.h"
#include "Paddle.h"

Ball::Ball(float pX, float pY)
{
	this->position.x = pX;
	this->position.y = pY;
	this->speed = 300.0f;
	this->angle = 45;
	this->radius = 10.0f;
	this->color = sf::Color(255, 255, 255);
	for (int i = 0; i < 10; i++) {
		this->trails.push_back(sf::Vector2f(this->position.x, this->position.y));
	}

	this->shape.setRadius(this->radius);
	this->shape.setOrigin(this->radius, this->radius);
	this->shape.setOutlineThickness(3);
}

void Ball::update()
{
	this->velocity.x = this->speed * cosf(this->angle * 3.14f / 180);
	this->velocity.y = this->speed * sinf(this->angle * 3.14f / 180);
	//std::cout << this->angle << std::endl;
	this->position.x += this->velocity.x * dt.asSeconds();
	this->position.y += this->velocity.y * dt.asSeconds();
	this->checkCollision();

	if (frameCount % 10 == 0) {
		this->trails.erase(this->trails.begin());
		this->trails.push_back(sf::Vector2f(this->position.x, this->position.y));
	}
}

void Ball::draw(sf::RenderWindow& window)
{
	this->shape.setPosition(this->position.x, this->position.y);
	this->shape.setFillColor(this->color);
	this->shape.setOutlineColor(sf::Color::White);

	for (int i = 0; i < this->trails.size(); i++) {
		this->trailShape.setRadius(this->radius * i / this->trails.size());
		this->trailShape.setOrigin(this->radius * i / this->trails.size(), this->radius * i / this->trails.size());
		this->trailShape.setPosition(this->trails.at(i));
		this->trailShape.setFillColor(this->color);
		window.draw(this->trailShape);
	}
	window.draw(this->shape);
}

void Ball::checkCollision()
{
	//screen
	if (this->position.y - this->radius<0 || this->position.y + this->radius>WINDOW_HEIGHT) {
		this->angle = -this->angle;
	}
	if (this->position.x + this->radius<0 || this->position.x - this->radius>WINDOW_WIDTH) {
		this->angle = 180 - this->angle;
	}
	//paddle
	if (this->position.x + this->radius > player->position.x - player->width / 2 &&
		this->position.x - this->radius < player->position.x + player->width / 2 &&
		this->position.y + this->radius > player->position.y - player->height / 2 &&
		this->position.y - this->radius < player->position.y + player->height / 2) {
		float collideAngle = atan2f(this->position.y - player->position.y, this->position.x - player->position.x) * 180 / 3.14f;
		float sideAngle = atan2f(this->radius + player->height / 2, this->radius + player->width / 2) * 180 / 3.14f;
		if (abs(collideAngle) > sideAngle && abs(collideAngle) < (180.0f - sideAngle)) {
			this->angle = -this->angle;
			this->angle = collideAngle;
			this->color = player->outlineColor;
		}
		else {
			this->angle = 180 - this->angle;
		}
	}
}