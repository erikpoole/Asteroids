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

#include "ship.hpp"
#include "asteroid.hpp"

int main(int argc, const char * argv[]) {
    
    // create the window sized to your screen
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; //antialaiasing for smoother shapes
    
    int windowHeight = sf::VideoMode::getDesktopMode().height;
    int windowWidth = sf::VideoMode::getDesktopMode().width;
    
    /*
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.jpg")){
        return -1;
    }
*/
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Asteroids",sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true); // vertical synchronization, call it once, after creating the window
    window.setMouseCursorVisible(false); //hide cursor
    
    Asteroid Asteroid1(50, 1000, 1000);
    Asteroid Asteroid2(150, 500, 500);
    Asteroid Asteroid3(100, 2000, 1000);

    Ship ourShip = Ship();
    ourShip.getShape().move(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height/2);
    
    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {

            /////USER INPUT SWITCHES/////
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                {
                    case sf::Keyboard::Left:
                        ourShip.getShape().rotate(10);
                        ourShip.getRotation(10);
                        break;
                    case sf::Keyboard::Right:
                        ourShip.getShape().rotate(-10);
                        break;
                    case sf::Keyboard::Up:
                        ourShip.getShape().move(100, 100);
                        break;
                    default:
                        break;
                }
                default:
                    break;
            }
        }
        
        window.clear(sf::Color::Black);

        
        window.draw(ourShip.getShape());
       
        sf::CircleShape asteroid(150); //50,100, 150
        asteroid.setOrigin(sf::Vector2f(-windowWidth/2, -windowHeight/2+400));

        Asteroid1.draw(window);
        Asteroid2.draw(window);
        Asteroid3.draw(window);
        
        window.display();
    }
}

