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
    const float speed[3] = {400.0f, 300.0f, 200.0f};
    const float rotation[3] = {1.5f, 1.0f, 0.5f};

    Asteroid(int startingLevel);
    
    void update(float dt);
    void draw(sf::RenderWindow &window);
    void Destroy();
    
private:
    sf::CircleShape asteroid;
    sf::Texture asteroidTexture;
    sf::Vector2f direction;
    int level;
};

#endif /* asteroid_hpp */
