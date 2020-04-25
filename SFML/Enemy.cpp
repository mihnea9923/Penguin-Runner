#include "Enemy.h"
#include "Player.h"
#include <chrono>
#include <thread>
using namespace std;
Enemy::Enemy()
{
	body.setSize(sf::Vector2f(50.f, 50.f));
	enemyTexture.loadFromFile("photos\\enemy.png");
	enemyTexture2.loadFromFile("photos\\enemy2.png");
	body.setTexture(&enemyTexture);
	body.setOrigin(body.getSize() / 2.0f);
}

void Enemy::SetPostion(sf::Vector2f vector, Player player, sf::RenderWindow& window)
{
	if (CheckColision(player))
	{
		std::this_thread::sleep_for(2s);
		window.close();
	}
	if (set == false)
	{
		body.setPosition(vector);
		set = true;
	}
	if (clock.getElapsedTime().asMilliseconds() > 3000)
	{
		body.setPosition(player.GetPosition().x + 600.f, 350.f);
		clock.restart();

	}
}
void Enemy::Draw(sf::RenderWindow& window)
{

	window.draw(body);
}
bool Enemy::CheckColision(Player player)
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
void Enemy::Update(float deltaTime)
{

	UpdateTexture();
	sf::Vector2f velocity;
	//velocity.x = -deltaTime * speed;
	velocity.y = 0;
	body.move(velocity);
}


void Enemy::UpdateTexture()
{

	if (clock2.getElapsedTime().asSeconds() > 0.3)
	{
		if (movement == false)
		{
			movement = true;
			body.setTexture(&enemyTexture);
		}
		else
		{
			movement = false;
			body.setTexture(&enemyTexture2);
		}
		clock2.restart();
	}

}
