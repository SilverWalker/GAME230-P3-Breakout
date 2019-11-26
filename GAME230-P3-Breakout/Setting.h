#pragma once
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "Powerup.h"
#include "LevelBuilder.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

extern bool mouseMode;

extern int score;
extern int life;
extern bool isGameOver;
extern int level;

extern sf::Clock deltaClock;
extern sf::Time dt;
extern int frameCount;

extern Paddle* player;
extern Ball* ball;
extern std::vector<Brick*> bricks;
extern std::vector<Powerup*> powerups;
extern LevelBuilder levelBuilder;

extern sf::Texture brickTexture;
extern sf::Texture brick2Texture;
extern sf::Color brickColors[];

extern sf::Color powerupColors[];


extern void loadAssets();
extern void resetGame();