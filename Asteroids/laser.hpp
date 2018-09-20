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

class Laser {
private:
    sf::RectangleShape shape;
    float rotation;
    float speed;
    sf::Clock lifetime;
    
public:
    //constructor
    Laser(sf::Vector2f location, float rotation);
  
    sf::RectangleShape& getShape() {return shape;}
    float& getRotation() {return rotation;}
    float& getSpeed() {return speed;}
    sf::Clock& getLifetime() {return lifetime;}
    

    
};



#endif /* laser_hpp */
