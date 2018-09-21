//  main.cpp
//  asteroids

//  Created by Ben Trueman on 9/17/18.
//  Copyright © 2018 Ben Trueman. All rights reserved.
//  Team: Ben Trueman & Erik Poole

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <math.h>
#include <vector>
#include "ship.hpp"
#include "asteroid.hpp"
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
    for(int i = 0; i < 3; i++){
        Asteroid asteroid(10);
        asteroids.push_back(asteroid);
    }

//    //make 20 asteroids
//    std::vector<Asteroid> asteroids = makeAsteroids(20);
    
    
////////////////////////////////////////***OBJECTS SETUP***////////////////////////////////////////
    
    Ship ourShip;
    ourShip.getShape().move(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height/2);
    
    std::vector<Laser> laserVector = {};
    sf::Clock laserClock;

    sf::Clock clock;
    
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
            moveObject(ourShip.getShape(), ourShip.getRotation(), ourShip.getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (laserClock.getElapsedTime().asSeconds() > .4) {
                laserClock.restart();
                laserVector.push_back(Laser(ourShip.getShape().getPosition(),ourShip.getRotation()));
            }
        }
        
        for (Asteroid& specificAsteroid : asteroids) {
            if (collision(ourShip.getShape(), specificAsteroid.getShape())) {
                clock.restart();
                laserVector = {};
                window.clear(sf::Color::Red);
                window.display();
                while (clock.getElapsedTime().asSeconds() < .5) {
                }
                ourShip.getShape().setPosition(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height/2);
                ourShip.getHealth()--;
                if (ourShip.getHealth() <= 0) {
                    exit(0);
                }
            }
        }

        for(int i = 0; i < asteroids.size(); i++) {
            for (int j = 0; j < laserVector.size(); j++) {
                if (collision(laserVector[j].getShape(), asteroids[i].getShape())) {
                    laserVector.erase(laserVector.begin()+j);
                    //asteroids.erase(asteroids.begin()+i); //error: Object of type 'Asteroid' cannot be assigned because its copy assignment operator is implicitly deleted
                    asteroids.push_back(asteroids[i].Destroy()); //this works!
                    j--;
                } else {
                    if (laserVector[j].getLifetime().getElapsedTime().asSeconds() > 1.5) {
                        laserVector.erase(laserVector.begin()+j);
                    }
                }
            }
//            if(asteroids[i].getLevel() < 0){
//                asteroids.erase(asteroids.begin()+i);
//            }
        }


////////////////////////////////////////***DRAWING SHAPES***////////////////////////////////////////
        
        window.clear(sf::Color::Black);
        window.draw(backgroundSprite);

        window.draw(ourShip.getShape());
        
        for (Laser& specificLaser : laserVector) {
                moveObject(specificLaser.getShape(), specificLaser.getRotation(), specificLaser.getSpeed());
                window.draw(specificLaser.getShape());
        }
        
        for (int i = 0; i < asteroids.size(); i++){
            asteroids[i].draw(window);
            asteroids[i].update(dtAsSeconds);
//            if (asteroids[i].getLifetime().getElapsedTime().asSeconds() > 3){
//                asteroids[i].Destroy();
//            }
        }
        
        window.display();
        
    }
}

