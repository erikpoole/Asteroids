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
#include <cstdlib>
#include "world.hpp"
#define DEG2RAD 3.14159f / 180.0f

///Asteroid constructor. Randomly assigns the asteroid a position, sets the origin as the center of the asteroid, loads the texture jpg, and randomly assigns a direction for the asteroid to move
Asteroid::Asteroid(int staringLevel){
    unsigned seed = std::chrono::system_clock::now()
                    .time_since_epoch()
                    .count();
    srand(seed);
    lifetime.restart();
    
    level = staringLevel;
    int randRadius = (level+1)*50; //50,100,150
    asteroid.setRadius(randRadius);
    
    int windowWidth = sf::VideoMode::getDesktopMode().width;
    int windowHeight = sf::VideoMode::getDesktopMode().height;
    
    //logic to make asteroids spawn on borders
    int xPosition[] = {0, 1, windowWidth};
    int random = rand()%3;
    
    if(xPosition[random] == 0 || xPosition[random] == windowWidth){
        asteroid.setPosition(xPosition[random],(rand() % windowHeight));
    } else {
        int yPosition[] = {0, windowHeight};
        int random = rand()%2;
        asteroid.setPosition((rand() % windowWidth), yPosition[random]);
     }
    
    asteroid.setOrigin(asteroid.getRadius(),asteroid.getRadius()); //make circle rotate around its center
    
    //load texture
    if (!asteroidTexture.loadFromFile("asteroid.jpg")) {
        std::cout << "ERROR asteroid.jpg" << std::endl;
    }
    asteroid.setTexture(&asteroidTexture);
    asteroid.setTextureRect(sf::IntRect(0, 0, 512, 512));

    int angle = rand() % 360;
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));
    
    float rotationDirection[4] = {-1.0, -0.5, 0.5, 1.0};
    int index = rand()%4;
    asteroidRotation = rotationDirection[index]; //random initial rotation value
    
    
}
///updates asteroid position, checks asteroid position and moves asteroid to the other side of the screen if it moves offscreen
void Asteroid::update(float elapsedTime){
    
//    if (asteroid.getPosition().x < -20.0f){
//        asteroid.setPosition(sf::VideoMode::getDesktopMode().width,0);
//    } else if (asteroid.getPosition().x > sf::VideoMode::getDesktopMode().width){
//        asteroid.setPosition(0, asteroid.getPosition().y);
//    }
//    if (asteroid.getPosition().y < -20.0f){
//        asteroid.setPosition(asteroid.getPosition().x,sf::VideoMode::getDesktopMode().height);
//    } else if (asteroid.getPosition().y > sf::VideoMode::getDesktopMode().height){
//        asteroid.setPosition(asteroid.getPosition().x,0.0);
//    }
  
    if (asteroid.getPosition().x < 0 - asteroid.getRadius()) {
        asteroid.move(sf::VideoMode::getDesktopMode().width + asteroid.getRadius(), 0);
    }
    if (asteroid.getPosition().x > sf::VideoMode::getDesktopMode().width + asteroid.getRadius()) {
        int width = sf::VideoMode::getDesktopMode().width + asteroid.getRadius();
        asteroid.move(width * -1, 0);
    }
    if (asteroid.getPosition().y < 0 - asteroid.getRadius()) {
        asteroid.move(0, sf::VideoMode::getDesktopMode().height + asteroid.getRadius());
    }
    if (asteroid.getPosition().y > sf::VideoMode::getDesktopMode().height + asteroid.getRadius()) {
        int height = sf::VideoMode::getDesktopMode().height + asteroid.getRadius();
        asteroid.move(0, height * -1);
    }
    
    sf::Vector2f distance = direction * speed[level] * elapsedTime;
    asteroid.move(distance);
    asteroid.rotate(asteroidRotation + rotation[level]);
}
///draws the asteroid shape in the window, rotates asteroid based off of asteroid level
void Asteroid::draw(sf::RenderWindow &window)
{
    window.draw(asteroid);
}

///downgrades the asteroid level, resets the radius and origin, and generates a new random direction
void Asteroid::Destroy(){
    level--;
    lifetime.restart();
    asteroid.setRadius((level+1)*50);
    asteroid.setOrigin(asteroid.getRadius(),asteroid.getRadius()); //update origin for new size
    float angle = rand() % 360;
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));
    
    //TODO: create second asteroid with opposite direction. Add it to the class vector of asteroids.
    //Asteroid child(level);
    
}
