#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
class Fire
{
public:
	Fire(int speed);
	void SetPostion(sf::Vector2f, Player play, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	bool CheckColision(Player player);
	sf::Vector2f GetPosition() { return  body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape body;
	int speed;
	bool set = false;
	bool movement = false;
	sf::Texture fireTexture;
	sf::Clock clock;
	sf::Clock clock2;



};


