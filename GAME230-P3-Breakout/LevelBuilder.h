#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class LevelBuilder {
public:
	int gridX;
	int gridY;
	int maxLevel;
	std::vector<std::vector<std::vector<int>>> levels;

	LevelBuilder();
	void buildLevel(int level);
};