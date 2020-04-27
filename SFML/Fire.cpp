#include "Fire.h"
#include "Player.h"
#include "Enemy.h"
#include <chrono>
#include <thread>
using namespace std;
Fire::Fire(int speed)
{
	body.setSize(sf::Vector2f(70.f, 70.f));
	fireTexture.loadFromFile("photos\\fire.png");
	this->speed = speed;
	body.setTexture(&fireTexture);
	body.setOrigin(body.getSize());
}

void Fire::SetPostion(sf::Vector2f vector,Player player, sf::RenderWindow& window)
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
	if (clock.getElapsedTime().asMilliseconds() > 2800)
	{
		body.setPosition(player.GetPosition().x + 580.f, 350.f);
		clock.restart();

	}

}
//
void Fire::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
bool Fire::CheckColision(Player player)
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
void Fire::Update(float deltaTime)
{

	sf::Vector2f velocity;
	velocity.x = -deltaTime * speed;
	velocity.y = 0;
	body.move(velocity);
}




