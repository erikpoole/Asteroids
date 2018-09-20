//
//  laser.hpp
//  asteroids
//
//  Created by Erik Poole on 9/19/18.
//

#ifndef laser_hpp
#define laser_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <stdio.h>

///Object created by user input using location and rotation of 'ship' for construction
class Laser {
private:
    sf::RectangleShape shape;
    float rotation;
    float speed;
    sf::Clock lifetime;
    
public:
    //constructor
    Laser(sf::Vector2f location, float rotation);
  
    ///returns shape (and by extension - location)
    sf::RectangleShape& getShape() {return shape;}
    ///returns rotation
    float& getRotation() {return rotation;}
    ///returns speed
    float& getSpeed() {return speed;}
    ///returns time since object generation
    sf::Clock& getLifetime() {return lifetime;}
    

    
};



#endif /* laser_hpp */
