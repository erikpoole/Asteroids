//
//  ship.hpp
//  asteroids
//
//  Created by Erik Poole on 9/17/18.
//

#ifndef ship_hpp
#define ship_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <stdio.h>

class Ship{
private:
    sf::ConvexShape shape;
    sf::FloatRect bounds;
    
    float rotation;
    float speed;
    int health;

     
public:
    //constructor
    Ship();
    
    sf::ConvexShape& getShape() {return shape;}
    float& getRotation(float change) {return rotation += change;}
    const float& getSpeed() {return speed;}
    const float& getRotation() {return rotation;}
    
    void moveShip();
    //fireLaser();
};



#endif /* ship_hpp */
