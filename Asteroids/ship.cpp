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

#include <math.h>
#include <iostream>

#include "world.hpp"
#include "laser.hpp"

Ship::Ship() {
    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(0, -40));
    shape.setPoint(1, sf::Vector2f(40, 80));
    shape.setPoint(2, sf::Vector2f(0, 40));
    shape.setPoint(3, sf::Vector2f(-40, 80));
    
    sf::FloatRect bounds = shape.getGlobalBounds();
    
    rotation = 0;
    int health = 3;

}


//57.2958 is approximate conversion from degrees to radians
void Ship::moveShip() {
    shape.move(-sin(rotation/57.2958)*8, -cos(rotation/57.2958)*8);
    borderCrosser(shape);
}

//void Ship::fireLaser() {
  //  Laser newLaser = Laser(shape.getPosition());
//}
