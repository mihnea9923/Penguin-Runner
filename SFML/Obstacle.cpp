#include "Obstacle.h"
#include "Player.h"
#include <chrono>
#include <thread>
using namespace std;
Obstacle::Obstacle(int speed) 
{
	body.setSize(sf::Vector2f(50.f, 50.f));
	this->speed = speed;
	obstacleTexture2.loadFromFile("photos\\obstacle2.png");
	obstacleTexture1.loadFromFile("photos\\obstacle.png");
	body.setTexture(&obstacleTexture1);
	body.setOrigin(body.getSize() / 2.0f);
	jumpedOver = false;
}


void Obstacle::SetPostion(sf::Vector2f vector,Player player,sf::RenderWindow& window)
{
	if (CheckColision(player) && player.invincible == false)
	{
		std::this_thread::sleep_for(2s);
		window.close();
	}
	if (set == false)
	{
		body.setPosition(vector);
		set = true;
	}
	if (clock.getElapsedTime().asMilliseconds() > 5000)
	{
		body.setPosition(player.GetPosition().x +600.f , 350.f );
		clock.restart();
		jumpedOver = false;
		
	}
}
void Obstacle::Draw(sf::RenderWindow& window)
{
	
	window.draw(body);
}
bool Obstacle::CheckColision(Player player)
{
	auto collider = player.GetCollider();
	sf::Vector2f otherPosition = collider.GetPosition();
	sf::Vector2f otherHalfSize = collider.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
	float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);
	if (intersectX < -20.0f && intersectY < 0.0f)
	{
		return true;
	}
	return false;
	auto other = player.GetBody();
	other.setOrigin(other.getSize().x / 2, other.getSize().y / 2);
		
}
void Obstacle::Update(float deltaTime)
{
	
	UpdateTexture();
	sf::Vector2f velocity;
	velocity.x = -deltaTime * speed;
	velocity.y = 0;
	body.move(velocity);
}


void Obstacle::UpdateTexture()
{
	
	if (clock2.getElapsedTime().asSeconds() > 0.3)
	{
	
		if (movement == false)
		{
			movement = true;
			body.setTexture(&obstacleTexture1);
		}
		else
		{
			movement = false;
			body.setTexture(&obstacleTexture2);
		}
		clock2.restart();
	}

}
