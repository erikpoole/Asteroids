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
    
public:
    //constructor
    Laser(sf::Vector2f location, float rotation);
  
    sf::RectangleShape& getShape() {return shape;}
    //sf::RectangleShape& getShape(float move) {return rotation += change;}
    float& getRotation() {return rotation;}
    

    
};



#endif /* laser_hpp */
