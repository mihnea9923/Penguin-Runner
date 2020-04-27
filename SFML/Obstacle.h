#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
class Obstacle
{
public:
	Obstacle(int speed);
	void SetPostion(sf::Vector2f,Player play, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	void UpdateTexture();
	bool CheckColision(Player player);
	sf::Vector2f GetPosition() { return  body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
	
	
private:
	sf::RectangleShape body;
	bool set = false;
	int speed;
	bool movement = false;
	sf::Texture obstacleTexture1;
	sf::Texture obstacleTexture2;
	sf::Clock clock;
	sf::Clock clock2;

	
	
};

