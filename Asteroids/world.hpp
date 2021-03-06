//
//  world.hpp
//  asteroids
//
//  Created by Erik Poole on 9/19/18.
//

#ifndef world_hpp
#define world_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <stdio.h>


void moveObject(sf::Shape& input, float angle, float speed);

void borderCrosser(sf::Shape& input);

bool collision(sf::Shape& shape, const sf::CircleShape& asteroid);

#endif /* world_hpp */
