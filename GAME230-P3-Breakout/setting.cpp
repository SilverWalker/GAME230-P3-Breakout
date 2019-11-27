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
std::vector<Brick*> fixedBricks;
std::vector<Powerup*> powerups;
LevelBuilder levelBuilder;

sf::Texture brickTexture;
sf::Texture brick2Texture;
sf::Texture brickFixedTexture;
sf::Color brickColors[10] = { sf::Color(229, 115, 115), sf::Color(255, 183, 77), sf::Color(255, 241, 118), sf::Color(129, 199, 132),
							  sf::Color(79, 195, 247), sf::Color(121, 134, 203), sf::Color(186, 104, 200), 
							  sf::Color(250, 250, 250), sf::Color(150, 150, 150), sf::Color(80, 80, 80) };

sf::Texture powerupTextures[5];

sf::Color powerupColors[10] = { sf::Color(129, 199, 132), sf::Color(229, 115, 115), sf::Color(129, 199, 132), sf::Color(229, 115, 115),
							  sf::Color(79, 195, 247), sf::Color(121, 134, 203), sf::Color(186, 104, 200),
							  sf::Color(250, 250, 250), sf::Color(150, 150, 150), sf::Color(80, 80, 80) };

std::vector<Wave*> waves;

sf::SoundBuffer hitPaddleBuffer;
sf::SoundBuffer hitWallBuffer;
sf::SoundBuffer hitBrickBuffer;
sf::SoundBuffer destroyBrickBuffer;
sf::SoundBuffer hitFixedBrickBuffer;
sf::SoundBuffer loseBuffer;
sf::SoundBuffer winBuffer;
sf::SoundBuffer powerupBuffer;
sf::Sound sound;
sf::Sound destroySound;
sf::Sound pupSound;
sf::Sound stageSound;

void loadAssets() {
	brickTexture.loadFromFile("asset/texture/brick.png");
	brick2Texture.loadFromFile("asset/texture/brick-2.png");
	brickFixedTexture.loadFromFile("asset/texture/brick-fixed.png");
	for (int i = 0; i < 5; i++) {
		powerupTextures[i].loadFromFile("asset/texture/powerup-" + std::to_string(i) + ".png");
	}

	hitPaddleBuffer.loadFromFile("asset/sound/hitPaddle.wav");
	hitWallBuffer.loadFromFile("asset/sound/hitWall.wav");
	hitBrickBuffer.loadFromFile("asset/sound/hitBrick.wav");
	destroyBrickBuffer.loadFromFile("asset/sound/destroyBrick.wav");
	hitFixedBrickBuffer.loadFromFile("asset/sound/hitFixedBrick.wav");
	loseBuffer.loadFromFile("asset/sound/lose.wav");
	winBuffer.loadFromFile("asset/sound/win.wav");
	powerupBuffer.loadFromFile("asset/sound/powerup.wav");
}

void resetGame() {
	score = 0;
	life = 3;
	level = 1;

	levelBuilder.buildLevel(level);
	isGameOver = false;
}

void playSound(int soundId) {
	switch (soundId) {
	case 0:
		sound.setBuffer(hitPaddleBuffer);
		sound.play();
		break;
	case 1:
		sound.setBuffer(hitWallBuffer);
		sound.play();
		break;
	case 2:
		sound.setBuffer(hitBrickBuffer);
		sound.play();
		break;
	case 3:
		destroySound.setBuffer(destroyBrickBuffer);
		destroySound.play();
		break;
	case 4:
		sound.setBuffer(hitFixedBrickBuffer);
		sound.play();
		break;
	case 5:
		stageSound.setBuffer(loseBuffer);
		stageSound.play();
		break;
	case 6:
		stageSound.setBuffer(winBuffer);
		stageSound.play();
		break;
	case 7:
		pupSound.setBuffer(powerupBuffer);
		pupSound.play();
		break;
	}
}