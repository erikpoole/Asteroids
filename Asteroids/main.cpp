//  main.cpp
//  asteroids

//  Created by Ben Trueman on 9/17/18.
//  Copyright © 2018 Ben Trueman. All rights reserved.
//  Team: Ben Trueman & Erik Poole

/*
 class Asteroid{
 private:
    int size;
 
 public:
    constructor
    Destroy/Construct Smaller Asteroids
    method - Generate Random Asteroids
    method - Move Asteroids
 
 }
 
 class Ship{
    private:
    int health
    ConvexShape shape;
 
 public:
    constructor
    destructor/destroy ship
    method - Move user input movement (WASD? Mouse?)    - speed?
    method - rotation
    method - fire laser
    method - move across screen border
 
 }
 
 
 class Laser{
 private:
    int size;
    int timeofsurivival;
 
 public:
    constructor
 
 }
 
 
 class Collisions{
 private:
 
 public:
    method - Asteroid/Ship Collision
    method - Asteroid/Laser Collision
 }
 
 
 Order to Implement -
 Ship
 Asteroid
 Collision
 Laser
 
 Tests -
 Moving ship orthagonally
 Rotating ship
 Moving ship across borders
 
 Creating and Moving Asteroid automatically
 Test Asteroid Destruction (time delay, no collisions yet)
 
 Collisions between asteroid and ship
 Collisions between asteroid and asteroid (?)
 
 Fire Laser from point (shifting direction)
 Fire Laser from front of ship
 Laser appropriately decays over time
 Collision between Laser and asteroid
 
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <math.h>

#include "ship.hpp"
#include "asteroid.hpp"
#include <vector>
#include "world.hpp"
#include "laser.hpp"


int main(int argc, const char * argv[]) {
    
////////////////////////////////////////***WINDOW SETUP***////////////////////////////////////////
    
    // create the window sized to your screen
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; //antialaiasing for smoother shapes
    
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background2.jpg")){
        return -1;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Asteroids", sf::Style::Fullscreen, settings);
    window.setVerticalSyncEnabled(true); // vertical synchronization, call it once, after creating the window
    window.setMouseCursorVisible(false); //hide cursor
    
    //create 20 asteroids - looses reference to the texture
    std::vector<Asteroid> asteroids;
    for(int i = 0; i < 20; i++){
        Asteroid asteroid(2);
        asteroids.emplace_back(asteroid);
    }
    Asteroid asteroid1(2);
    Asteroid asteroid2(2);
    Asteroid asteroid3(2);
    
    Ship ourShip = Ship();
    
////////////////////////////////////////***OBJECTS SETUP***////////////////////////////////////////

    ourShip.getShape().move(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height/2);
    
    std::vector<Laser> laserVector = {};
    sf::Clock laserClock;

    sf::Clock clock;
    
    sf::CircleShape collisionTest(500);

    
////////////////////////////////////////***USER INPUT SETUP***////////////////////////////////////////
    
    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        
        
        /////USER INPUT SWITCHES/////
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                    window.close();
                    break;
            }
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            break;
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ourShip.getShape().rotate(-4);
            ourShip.getRotation(4);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ourShip.getShape().rotate(4);
            ourShip.getRotation(-4);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            //ourShip.moveShip();
            moveObject(ourShip.getShape(), ourShip.getRotation(), ourShip.getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (laserClock.getElapsedTime().asSeconds() > .4) {
                laserClock.restart();
                laserVector.push_back(Laser(ourShip.getShape().getPosition(),ourShip.getRotation()));
            }
        }
        

        if (collisionTest.getGlobalBounds().intersects(ourShip.getShape().getGlobalBounds())) {
            laserClock.restart();
            laserVector = {};
            window.clear(sf::Color::Red);
//            sf::Text deathText;
//            deathText.setPosition(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height/2);
//            deathText.setFillColor(sf::Color::Black);
//            deathText.setString("You Crashed! :(");
//            window.draw(deathText);
            window.display();
            while (laserClock.getElapsedTime().asSeconds() < 1) {
            }
            ourShip.getShape().setPosition(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height/2);
        }

        
////////////////////////////////////////***DRAWING SHAPES***////////////////////////////////////////
        
        window.clear(sf::Color::Black);
        window.draw(backgroundSprite);

        window.draw(ourShip.getShape());
        
        for (Laser& specificLaser : laserVector) {
            if (specificLaser.getLifetime().getElapsedTime().asSeconds() < 1.5) {
                moveObject(specificLaser.getShape(), specificLaser.getRotation(), specificLaser.getSpeed());
                window.draw(specificLaser.getShape());
            }
        }
        
        window.draw(collisionTest);
        
        for (int i = 0; i < 20; i++){
            asteroids[i].draw(window);
            asteroids[i].update(dtAsSeconds);
//            if (asteroids[i].getLifetime().getElapsedTime().asSeconds() > 3){
//                asteroids[i].Destroy();
//            }
        }
        asteroid1.draw(window);
        asteroid1.update(dtAsSeconds);
        
        ourShip.getShape().getPoint(0);
        
        window.display();
        
    }
    
    
}

