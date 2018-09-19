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

Asteroid:: Asteroid(){
    asteroid.setRadius(100); //50,100,150
    if (!asteroidTexture.loadFromFile("asteroid.jpg"))
    {
        std::cout << "ERROR asteroid.jpg" << std::endl;
    }
    asteroid.setTexture(&asteroidTexture);
    asteroid.setTextureRect(sf::IntRect(0, 0, 512, 512));
}

void Asteroid::update(float dt){
    
}
    
void Asteroid::draw(sf::RenderWindow &window)
{
    window.draw(asteroid);
}
