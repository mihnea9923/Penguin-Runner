#include "Lives.h"
void Lives::DrawLives(sf::RenderWindow& window)
{
	if (lives == 0)
	{
		std::this_thread::sleep_for(2s);
		window.close();
	}
	for (int i = 1; i <= lives; i++)
	{
		window.draw(hearts[i - 1]);
	}
}
void Lives::UpdateLives(Player& player)
{


	sf::RectangleShape heart1;
	heart1.setSize({ 50.f, 50.f });
	sf::RectangleShape heart2;
	heart2.setSize({ 50.f, 50.f });
	sf::RectangleShape heart3;
	heart3.setSize({ 50.f, 50.f });
	hearts.push_back(heart1);
	hearts.push_back(heart2);
	hearts.push_back(heart3);
	heartTexture.loadFromFile("heart.png");
	for (int i = 1; i <= lives; i++)
	{
		if (i == 1)
		{
			hearts[i - 1].setPosition(player.GetPosition().x + 500.f, player.GetPosition().y - 300.f);
		}
		else
		{
			hearts[i - 1].setPosition(hearts[i - 2].getPosition().x - 60.f, hearts[i - 2].getPosition().y);
		}
		hearts[i - 1].setTexture(&heartTexture);
	}

}