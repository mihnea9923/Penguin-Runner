#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
class Enemy
{
public:
	Enemy();
	void SetPostion(sf::Vector2f, Player play, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	void UpdateTexture();
	bool CheckColision(Player player);
	sf::Vector2f GetPosition() { return  body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape body;
	bool set = false;
	bool movement = false;
	sf::Texture enemyTexture;
	sf::Texture enemyTexture2;
	sf::Clock clock;
	sf::Clock clock2;



};


