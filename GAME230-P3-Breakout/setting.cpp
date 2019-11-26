#include "Setting.h"
#include "Paddle.h"

int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 800;

bool mouseMode = true;

int score = 0;
int life = 3;
bool isGameOver = false;
int level = 2;

sf::Clock deltaClock;
sf::Time dt;
int frameCount = 0;

Paddle* player;
Ball* ball;
std::vector<Brick*> bricks;
std::vector<Powerup*> powerups;
LevelBuilder levelBuilder;

sf::Texture brickTexture;
sf::Texture brick2Texture;
sf::Color brickColors[10] = { sf::Color(229, 115, 115), sf::Color(255, 183, 77), sf::Color(255, 241, 118), sf::Color(129, 199, 132),
							  sf::Color(79, 195, 247), sf::Color(121, 134, 203), sf::Color(186, 104, 200), 
							  sf::Color(250, 250, 250), sf::Color(150, 150, 150), sf::Color(80, 80, 80) };

sf::Color powerupColors[10] = { sf::Color(129, 199, 132), sf::Color(229, 115, 115), sf::Color(150, 150, 150), sf::Color(255, 183, 77),
							  sf::Color(79, 195, 247), sf::Color(121, 134, 203), sf::Color(186, 104, 200),
							  sf::Color(250, 250, 250), sf::Color(150, 150, 150), sf::Color(80, 80, 80) };

void loadAssets() {
	brickTexture.loadFromFile("asset/texture/brick.png");
	brick2Texture.loadFromFile("asset/texture/brick-2.png");
}

void resetGame() {
	score = 0;
	life = 3;
	level = 1;

	levelBuilder.buildLevel(level);
	isGameOver = false;
}