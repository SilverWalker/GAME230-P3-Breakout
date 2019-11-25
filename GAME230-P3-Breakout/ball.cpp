#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Ball.h"
#include "Paddle.h"

Ball::Ball()
{
	this->speed = 300.0f + 200.0f * level;
	this->angle = -45;
	this->radius = 10.0f;
	this->isActive = false;
	this->position.x = player->position.x;
	this->position.y = player->position.y - player->height / 2 - this->radius;
	this->color = sf::Color(255, 255, 255);

	this->shape.setRadius(this->radius);
	this->shape.setOrigin(this->radius, this->radius);
	this->shape.setOutlineThickness(3);
}

void Ball::update()
{
	if (this->isActive) {
		this->velocity.x = this->speed * cosf(this->angle * 3.14f / 180);
		this->velocity.y = this->speed * sinf(this->angle * 3.14f / 180);
		this->position.x += this->velocity.x * dt.asSeconds();
		this->position.y += this->velocity.y * dt.asSeconds();
		this->checkCollision();
		if (this->position.x < 0) { this->position.x = this->radius; }
		if (this->position.x > WINDOW_WIDTH) { this->position.x = WINDOW_WIDTH - this->radius; }
		if (this->position.y < 0) { this->position.y = this->radius; }

		if (frameCount % 50 == 0) {
			this->trails.erase(this->trails.begin());
			this->trails.push_back(sf::Vector2f(this->position.x, this->position.y));
		}
	}
	else {
		this->position.x = player->position.x;
		this->position.y = player->position.y - player->height / 2 - this->radius;
	}
}

void Ball::draw(sf::RenderWindow& window)
{
	this->shape.setPosition(this->position.x, this->position.y);
	this->shape.setFillColor(this->color);
	this->shape.setOutlineColor(sf::Color::White);

	if (this->isActive) {
		for (int i = 0; i < this->trails.size(); i++) {
			this->trailShape.setRadius(this->radius * i / this->trails.size());
			this->trailShape.setOrigin(this->radius * i / this->trails.size(), this->radius * i / this->trails.size());
			this->trailShape.setPosition(this->trails.at(i));
			sf::Color trailColor = this->color;
			trailColor.a = 150;
			this->trailShape.setFillColor(trailColor);
			window.draw(this->trailShape);
		}
	}
	window.draw(this->shape);
}

void Ball::checkCollision()
{
	//screen
	if (this->position.x - this->radius < 0 || this->position.x + this->radius > WINDOW_WIDTH) {
		this->angle = 180 - this->angle;
	}
	if (this->position.y - this->radius < 0) {
		this->angle = -this->angle;
	}
	if (this->position.y - this->radius > WINDOW_HEIGHT) {
		if (life > 0) {
			life--;
			player->reset();
			this->reset();
		}
		else {
			this->reset();
			isGameOver = true;
		}
	}
	//paddle
	if (this->position.x + this->radius > player->position.x - player->width / 2 &&
		this->position.x - this->radius < player->position.x + player->width / 2 &&
		this->position.y + this->radius > player->position.y - player->height / 2 &&
		this->position.y - this->radius < player->position.y + player->height / 2) {
		float collideAngle = atan2f(this->position.y - player->position.y, this->position.x - player->position.x) * 180 / 3.14f;
		float sideAngle = atan2f(this->radius + player->height / 2, this->radius + player->width / 2) * 180 / 3.14f;
		if (abs(collideAngle) > sideAngle && abs(collideAngle) < (180.0f - sideAngle)) {
			this->angle = round(collideAngle / 10) * 10;
		}
		else {
			this->angle = 180 - this->angle;
		}
	}
	///brick
	for (int i = 0; i < bricks.size(); i++) {
		if (this->position.x + this->radius > bricks.at(i)->position.x - bricks.at(i)->width / 2 &&
			this->position.x - this->radius < bricks.at(i)->position.x + bricks.at(i)->width / 2 &&
			this->position.y + this->radius > bricks.at(i)->position.y - bricks.at(i)->height / 2 &&
			this->position.y - this->radius < bricks.at(i)->position.y + bricks.at(i)->height / 2) {
			float collideAngle = atan2f(this->position.y - bricks.at(i)->position.y, this->position.x - bricks.at(i)->position.x) * 180 / 3.14f;
			float sideAngle = atan2f(this->radius + bricks.at(i)->height / 2, this->radius + player->width / 2) * 180 / 3.14f;
			if (abs(collideAngle) > sideAngle&& abs(collideAngle) < (180.0f - sideAngle)) {
				this->angle = -this->angle;
			}
			else {
				this->angle = 180 - this->angle;
			}
			this->color = bricks.at(i)->color;
			score += 50;
			delete bricks[i];
			bricks.erase(bricks.begin() + i);
		}
	}
}

void Ball::reset() {
	this->speed = 300.0f + 200.0f * level;
	this->angle = -45;
	ball->setActive(false);
	this->position.x = player->position.x;
	this->position.y = player->position.y - player->height / 2 - this->radius;
	this->color = sf::Color(255, 255, 255);
	this->trails.clear();
}

void Ball::setActive(bool isActive) {
	this->isActive = isActive;
	if (this->isActive) {
		this->trails.clear();
		for (int i = 0; i < 10; i++) {
			this->trails.push_back(sf::Vector2f(this->position.x, this->position.y));
		}		
	}
}