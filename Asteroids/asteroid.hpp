//
//  asteroid.hpp
//  asteroids
//
//  Created by Ben Trueman on 9/18/18.
//

#ifndef asteroid_hpp
#define asteroid_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Asteroid {
public:
    //constructor
    Asteroid(int radius, int x, int y);
    
    // dt, change in time
    void update(float dt);
    void draw(sf::RenderWindow &window);
    
private:
    sf::CircleShape asteroid;
    sf::Texture asteroidTexture;
    sf::Vector2f position;

};

#endif /* asteroid_hpp */
