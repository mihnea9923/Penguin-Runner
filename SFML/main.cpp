#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include "Weapon.h"
#include "Player.h"
#include "Collider.h"
#include "Platform.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "Score.h"
#include "Fire.h"
#include "Audio.h"
#include <vector>
#include "Lives.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML", sf::Style::Default | sf::Style::Resize | sf::Style::Close);
    sf::Texture playerTexture;
    //comme
    Lives* lives = new Lives();
     playerTexture.loadFromFile("photos\\tux_from_linux.png");
     srand(time(NULL));
     Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f , 100.0f , 150.f , lives);
     float deltaTime = 0.0f;
     sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(650.0f, 650.0f));
     sf::Clock clock ;
     Obstacle obstacle1(200);
     Enemy enemy1;
     Fire fire1(350);
     Weapon weapon;
     Audio playEffectSound;
	 playEffectSound.playFundalSong();
	 int counterSounds = 0;
     Score score;
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
        //player.Lives(player);
        sf::Vector2f vector(player.GetPosition().x + 500.f, player.GetPosition().y + 220);
        obstacle1.SetPostion(sf::Vector2f(vector.x ,350.f ),player,window,lives);
        enemy1.SetPostion(sf::Vector2f(vector.x, 350.f), player, window,fire1,lives);
        
        sf::Vector2f direction;
        
            if (platform.GetColider().checkColision(player.GetCollider(), direction, 1.f))
            {	
				
				if (counterSounds %7450==0) {
					playEffectSound.playMaybeNextTime();
				}
				counterSounds++;
                player.Collision(direction);
            }
        window.clear(sf::Color(10, 191, 255));
        view.setCenter(player.GetPosition().x + 250.f , player.GetPosition().y);
        window.setView(view);
        score.Update(player);
        lives->UpdateLives(player);
        obstacle1.Update(deltaTime);
        fire1.Update(deltaTime);
        player.Draw(window);
        score.Draw(window);
        obstacle1.Draw(window);
        enemy1.Draw(window);
        lives->DrawLives(window);
       // player.DrawLives(window);
        fire1.Draw(window);
        platform.Draw(window);
        //weapon.Update(player,window);
        window.display();
        score.IncreaseScore(player, obstacle1 , enemy1);
        
    }
    
    return 0;
}