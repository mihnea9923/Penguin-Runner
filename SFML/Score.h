#pragma once
#include "Obstacle.h"
class Score
{
public:
	void IncreaseScore(Player player, Obstacle& obstacle);
	int GetScore() { return score; }
private:
	int score = 0;
};

