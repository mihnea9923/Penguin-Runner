#include <SFML/Graphics.hpp>
#include <iostream>
#include "Weapon.h"
#include "Player.h"
#include "Collider.h"
#include "Game.h"
#include "Platform.h"
#include "Obstacle.h"
#include <vector>
int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML", sf::Style::Default | sf::Style::Resize | sf::Style::Close);
    sf::Texture playerTexture;
     playerTexture.loadFromFile("photos\\tux_from_linux.png");
     srand(time(NULL));
     Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f , 100.0f , 150.f);
     float deltaTime = 0.0f;
     sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(650.0f, 650.0f));
     sf::Clock clock ;
     sf::CircleShape circle;
     circle.setRadius(25.f);
     circle.setFillColor(sf::Color::Yellow);
     circle.setPosition(350.f, 100.f);
     Obstacle obstacle1(200);
     Weapon weapon;
     while (window.isOpen())
    {
        deltaTime = clock.getElapsedTime().asSeconds();
        if (deltaTime > 1.f / 20.f)
        {
            deltaTime = 1.f / 20.f;
        }
       
        Platform platform(nullptr, sf::Vector2f(1200.f, 250.f), sf::Vector2f(player.GetPosition().x, 500.f));
        clock.restart();
        sf::Event evnt;

        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
           
            }
      
        }
        player.Update(deltaTime);
        sf::Vector2f vector(player.GetPosition().x + 500.f, player.GetPosition().y + 220);
        obstacle1.SetPostion(sf::Vector2f(vector.x ,350.f ),player,window);
        sf::Vector2f direction;
       
            if (platform.GetColider().checkColision(player.GetCollider(), direction, 1.f))
            {
                player.Collision(direction);
            }
        view.setCenter(player.GetPosition().x + 250.f , player.GetPosition().y);
        window.clear(sf::Color(10, 191, 255));
        window.setView(view);
        player.Draw(window);
        obstacle1.Update(deltaTime);
        obstacle1.Draw(window);
        platform.Draw(window);
        circle.setPosition(player.GetPosition().x + 500.f, player.GetPosition().y - 300.f);
        weapon.Update(player,window);
        window.draw(circle);
        window.display();
        
    }
    
    return 0;
}