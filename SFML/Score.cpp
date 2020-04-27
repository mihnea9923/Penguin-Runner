#include "Score.h"

void Score::IncreaseScore(Player player, Obstacle& obstacle)
{
	if ((player.GetPosition().x > obstacle.GetPosition().x) && (obstacle.jumpedOver == false))
	{
		obstacle.jumpedOver = true;
		score++;
	}
}
