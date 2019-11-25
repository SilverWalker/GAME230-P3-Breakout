#include "Setting.h"
#include "Paddle.h"

int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 800;

bool mouseMode = true;

int score = 0;
int life = 3;
bool isGameOver = false;
int level = 1;

sf::Clock deltaClock;
sf::Time dt;
int frameCount = 0;

Paddle* player;
Ball* ball;
std::vector<Brick*> bricks;
std::vector<Powerup*> powerups;

sf::Texture brickTexture;
sf::Color brickColors[10] = { sf::Color(229, 115, 115), sf::Color(255, 183, 77), sf::Color(255, 241, 118), sf::Color(129, 199, 132),
							  sf::Color(79, 195, 247), sf::Color(121, 134, 203), sf::Color(186, 104, 200), 
							  sf::Color(250, 250, 250), sf::Color(150, 150, 150), sf::Color(50, 50, 50) };

sf::Color powerupColors[10] = { sf::Color(129, 199, 132), sf::Color(229, 115, 115), sf::Color(150, 150, 150), sf::Color(255, 183, 77),
							  sf::Color(79, 195, 247), sf::Color(121, 134, 203), sf::Color(186, 104, 200),
							  sf::Color(250, 250, 250), sf::Color(150, 150, 150), sf::Color(50, 50, 50) };

void loadAssets() {
	brickTexture.loadFromFile("asset/texture/brick.png");
}

void resetGame() {
	score = 0;
	life = 3;
	level = 1;

	player->reset();
	ball->reset();
	bricks.clear();
	powerups.clear();
	for (int i = 0; i < 100; i++) {
		if ((i / 10) % 2 == 0) {
			bricks.push_back(new Brick((i % 10) * 100 + 50, int(i / 10) * 40 + 20 + 50, brickColors[i % 10]));
		}
	}
	isGameOver = false;
}