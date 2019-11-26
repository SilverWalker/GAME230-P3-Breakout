#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Brick.h"
#include "LevelBuilder.h"

LevelBuilder::LevelBuilder()
{
	this->gridX = 10;
	this->gridY = 10;
	this->maxLevel = 5;
	this->levels = { 
		{	//level 1 
			{0,0,1}, {1,1,1}, {2,2,1}, {3,3,1}, {4,4,1}, {5,5,1}, {6,6,1}, {7,0,1}, {8,1,1}, {9,2,1},
			{20,0,1}, {21,1,1}, {22,2,1}, {23,3,1}, {24,4,1}, {25,5,1}, {26,6,1}, {27,0,1}, {28,1,1}, {29,2,1},
			{40,0,1}, {41,1,1}, {42,2,1}, {43,3,1}, {44,4,1}, {45,5,1}, {46,6,1}, {47,0,1}, {48,1,1}, {49,2,1},
			{60,0,1}, {61,1,1}, {62,2,1}, {63,3,1}, {64,4,1}, {65,5,1}, {66,6,1}, {67,0,1}, {68,1,1}, {69,2,1},
			{80,0,1}, {81,1,1}, {82,2,1}, {83,3,1}, {84,4,1}, {85,5,1}, {86,6,1}, {87,0,1}, {88,1,1}, {89,2,1}
		},
		{	//level 2
			{40,0,1}, {41,0,1}, {42,0,1}, {43,0,1}, {44,0,1},
			{50,1,1}, {51,1,1}, {52,1,1}, {53,1,1}, {54,1,1}, {55,1,1},
			{60,2,1}, {61,2,1}, {62,2,1}, {63,2,1}, {64,2,1}, {65,2,1}, {66,2,1},
			{70,3,1}, {71,3,1}, {72,3,1}, {73,3,1}, {74,3,1}, {75,3,1}, {76,3,1}, {77,3,1},
			{80,4,1}, {81,4,1}, {82,4,1}, {83,4,1}, {84,4,1}, {85,4,1}, {86,4,1}, {87,4,1}, {88,4,1},
			{90,8,2}, {91,8,2}, {92,8,2}, {93,8,2}, {94,8,2}, {95,8,2}, {96,8,2}, {97,8,2}, {98,8,2}
		},
		{	//level 3
			{20,0,1}, {21,1,1}, {22,2,1}, {23,3,1}, {24,4,1}, {25,5,1}, {26,6,1}, {27,7,1}, {28,8,1}, {29,9,1}
		},
		{	//level 4
			{40,0,1}, {41,1,1}, {42,2,1}, {43,3,1}, {44,4,1}, {45,5,1}, {46,6,1}, {47,7,1}, {48,8,1}, {49,9,1}
		},
		{	//level 5
			{60,0,1}, {61,1,1}, {62,2,1}, {63,3,1}, {64,4,1}, {65,5,1}, {66,6,1}, {67,7,1}, {68,8,1}, {69,9,1}
		}
	};
}

void LevelBuilder::buildLevel(int level)
{
	int stage = (level - 1) % this->maxLevel;
	player->reset();
	ball->reset();
	bricks.clear();
	powerups.clear();
	/*for (int i = 0; i < 100; i++) {
		if ((i / 10) % 2 == 0) {
			bricks.push_back(new Brick((i % 10) * 100 + 50, int(i / 10) * 40 + 20 + 50, i % 10, 2));
		}
	}*/
	std::cout << this->levels.at(stage).size() << std::endl;
	for (int i = 0; i < this->levels.at(stage).size(); i++) {
		bricks.push_back(new Brick((this->levels[stage][i][0] % 10) * 100 + 50, int(this->levels[stage][i][0] / 10) * 40 + 20 + 50, this->levels[stage][i][1], this->levels[stage][i][2]));
	}
}