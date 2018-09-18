//
//  ship.cpp
//  asteroids
//
//  Created by Erik Poole on 9/17/18.
//

#include "ship.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


Ship::Ship() {
    shape.setPointCount(4);
    
    shape.setPoint(0, sf::Vector2f(100, 100));
    shape.setPoint(1, sf::Vector2f(150, 300));
    shape.setPoint(2, sf::Vector2f(100, 250));
    shape.setPoint(3, sf::Vector2f(50, 300));
    
}

 
/*
 sf::CircleShape shape(100);
 shape.setFillColor(sf::Color(100,100,100));
 window.draw(shape);
 */

