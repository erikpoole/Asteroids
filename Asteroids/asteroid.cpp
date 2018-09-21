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
   
    
    //set random direction
    int angle = rand() % 360;
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));
    
    //set random rotation
    float rotationDirection[4] = {-1.0, -0.5, 0.5, 1.0};
    int index = rand() % 4;
    asteroidRotation = rotationDirection[index];
}
///updates asteroid position, checks asteroid position and moves asteroid to the other side of the screen if it moves offscreen, rotates asteroid based off of asteroid level + asteroidRotation
void Asteroid::update(float elapsedTime){
    
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
///draws the asteroid shape in the window
void Asteroid::draw(sf::RenderWindow &window)
{
    asteroid.setTexture(&asteroidTexture);
    asteroid.setTextureRect(sf::IntRect(0, 0, 512, 512));
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
    
    //return a copy of the asteroid
    
    //return Asteroid child(level). Make this return an asteroid instead of void
}

//fill vector with number of level 2 asteroids
std::vector<Asteroid> makeAsteroids(int number){
    std::vector<Asteroid> asteroids;
    for(int i = 0; i < number; i++){
        Asteroid asteroid(2);
        asteroids.push_back(asteroid);
    }
    return asteroids;
}

//draw all asteroids in vector
void drawAsteroids(std::vector<Asteroid> asteroids, sf::RenderWindow &window, float elapsedTime){
    for (int i = 0; i < asteroids.size(); i++){
        asteroids[i].draw(window);
        asteroids[i].update(elapsedTime);
    }
}

//destroy asteroid i in the vector


