//
//  asteroid.cpp
//  asteroids
//
//  Created by Ben Trueman on 9/18/18.
//

#include "asteroid.hpp"
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <random>
#include <ctime>

Asteroid:: Asteroid(int radius, int x, int y){
    asteroid.setRadius(100); //50,100,150
    asteroid.setPosition(x, y);
    asteroid.setOrigin(asteroid.getRadius(),asteroid.getRadius()); //make circle rotate around its center
    if (!asteroidTexture.loadFromFile("asteroid.jpg"))
    {
        std::cout << "ERROR asteroid.jpg" << std::endl;
    }
    asteroid.setTexture(&asteroidTexture);
    asteroid.setTextureRect(sf::IntRect(0, 0, 512, 512));
}

void Asteroid::update(float elapsedTime){

    if (asteroid.getPosition().x < -10.0f){
        asteroid.setPosition(sf::VideoMode::getDesktopMode().width,0);
    } else if (asteroid.getPosition().x > sf::VideoMode::getDesktopMode().width){
        asteroid.setPosition(0, asteroid.getPosition().y);
    }
    if (asteroid.getPosition().y < -10.0f){
//       position.y = sf::VideoMode::getDesktopMode().height;
        asteroid.setPosition(asteroid.getPosition().x,sf::VideoMode::getDesktopMode().height);
    } else if (asteroid.getPosition().y > sf::VideoMode::getDesktopMode().height){
        asteroid.setPosition(asteroid.getPosition().x,0.0);
    }
    asteroid.move(position.x+7,position.y+5);
}
    
void Asteroid::draw(sf::RenderWindow &window)
{
    asteroid.rotate(0.5);
    window.draw(asteroid);
}
