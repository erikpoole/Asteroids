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
    int health;
    int size;

    
public:
    //constructor
    Ship();
    sf::ConvexShape shape;
    
    //destructor/destroy ship
    
};



#endif /* ship_hpp */
