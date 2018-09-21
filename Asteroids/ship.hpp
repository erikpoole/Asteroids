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

///Player class that responds to user input
class Ship{
private:
    sf::ConvexShape shape;
                //sf::FloatRect bounds;
    
    float rotation;
    float speed;
    int health;

     
public:
    //constructor
    Ship();
    
    ///returns shape (and by extension - location)
    sf::ConvexShape& getShape() {return shape;}
    
    ///updates rotation based on input 'change'
    float& getRotation(float change) {return rotation += change;}
    
    /// returns present speed
    const float& getSpeed() {return speed;}
    
    /// returns present rotation
    const float& getRotation() {return rotation;}
    
    int& getHealth() {return health;}
    
    
    
    ///moves ship based on present speed and rotation
    void moveShip();
};



#endif /* ship_hpp */
