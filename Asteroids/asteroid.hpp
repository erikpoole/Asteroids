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

///The Asteroid class. Deals with all events related to asteroid creation, lifetime, and destruction.
class Asteroid {
public:
    ///speeds for each level of asteroid (largest asteroid is level 2)
    const float speed[3] = {550.0f, 300.0f, 200.0f};
    ///rotation speeds for each level of asteroid (largest asteroid is level 2)
    const float rotation[3] = {0.75f, 0.5f, 0.25f};
    ///tracks life of asteroid
    sf::Clock lifetime;
    
    ///asteroid constructor
    Asteroid(int startingLevel);
    ///updates asteroid movement
    void update(float dt);
    ///draws asteroid in the window
    void draw(sf::RenderWindow &window);
    ///downgrades the asteroid to a smaller asteroid, to be used in collisions with lasers
    void Destroy();
    ///returns how long the asteroid has been in existance for
    sf::Clock& getLifetime() {return lifetime;}
    
private:
    ///the asteroid shape
    sf::CircleShape asteroid;
    ///the asteroid texture
    sf::Texture asteroidTexture;
    ///the direction the asteroid will move
    sf::Vector2f direction;
    ///the asteroid's current level
    int level;
    float asteroidRotation;
};

#endif /* asteroid_hpp */
