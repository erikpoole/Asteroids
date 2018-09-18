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
 
 }
 
 class Ship{
 private:
    int health
    int size;
 
 public:
    constructor
    destructor/destroy ship
 
 }
 
 class Laser{
 private:
    int size;
 
 public:
    constructor
 
 }
 
 class Collisions{
 private:
 
 public:
 
 }
 
 Your plan should include at least the following information:
 What methods will they need?
 What data will they need to store?
 In what order will you implement them?
 What tests will you write along the way to verify that you're making progress?
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "ship.hpp"


int main(int argc, const char * argv[]) {
    // create the window sized to your screen
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; //antialaiasing for smoother shapes
    
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Asteroids",sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true); // vertical synchronization, call it once, after creating the window
    window.setMouseCursorVisible(false); //hide cursor
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        
        window.draw(Ship().shape);
        
        window.display();
    }
}
