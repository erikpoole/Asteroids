//
//  laser.cpp
//  asteroids
//
//  Created by Erik Poole on 9/19/18.
//

#include "laser.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>

Laser::Laser(sf::Vector2f inputLocation, float inputRotation) {
    shape.setSize(sf::Vector2f(5,-50));
    shape.setPosition(inputLocation);
    shape.setRotation(-inputRotation);
    rotation = inputRotation;
    
    /*
     shape.move(-sin(rotation/57.2958)*8, -cos(rotation/57.2958)*8);
    borderCrosser(shape);
    */
     
    sf::FloatRect bounds = shape.getGlobalBounds();
    
}
