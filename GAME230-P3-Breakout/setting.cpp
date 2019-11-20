#include "Setting.h"
#include "Paddle.h"

int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 800;

bool mouseMode = true;

int score = 0;
int life = 3;
bool isGameOver = false;

sf::Clock deltaClock;
sf::Time dt;
int frameCount = 0;

Paddle* player;
Ball* ball;