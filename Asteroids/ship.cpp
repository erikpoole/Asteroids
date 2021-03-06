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


///Default Constructor for ship.  Speed defined as 8, Rotation as 0, Health defined as 3, defines shape;
Ship::Ship() {
    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(0, -40));
    shape.setPoint(1, sf::Vector2f(40, 80));
    shape.setPoint(2, sf::Vector2f(0, 40));
    shape.setPoint(3, sf::Vector2f(-40, 80));
        
    rotation = 0;
    speed = 8;
    health = 3;
    

    

}
