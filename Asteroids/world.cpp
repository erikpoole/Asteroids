//
//  world.cpp
//  asteroids
//
//  Created by Erik Poole on 9/19/18.
//

#include "world.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>


//57.2958 is approximate conversion from degrees to radians
void moveObject(sf::Shape& object, float angle, float speed) {
    object.move(-sin(angle/57.2958)*speed, -cos(angle/57.2958)*speed);
    borderCrosser(object);
}

void borderCrosser(sf::Shape& input) {
    if (input.getPosition().x < 0) {
        input.move(sf::VideoMode::getDesktopMode().width, 0);
    }
    if (input.getPosition().x > sf::VideoMode::getDesktopMode().width) {
        int width = sf::VideoMode::getDesktopMode().width;
        input.move(width * -1, 0);
    }
    if (input.getPosition().y < 0) {
        input.move(0, sf::VideoMode::getDesktopMode().height);
    }
    if (input.getPosition().y > sf::VideoMode::getDesktopMode().height) {
        int height = sf::VideoMode::getDesktopMode().height;
        input.move(0, height * -1);
    }
}


bool collision(sf::Shape& shape, const sf::CircleShape& asteroid) {
    for (int i = 0; i < shape.getPointCount(); i++) {
        sf::Vector2f transformedPoint = shape.getTransform().transformPoint(shape.getPoint(i));
        float xdist = abs(transformedPoint.x - asteroid.getPosition().x);
        float ydist = abs(transformedPoint.y - asteroid.getPosition().y);
        float distance = sqrt((xdist*xdist)+(ydist*ydist));
        if (distance < asteroid.getRadius()) {
            return true;
        }
    }
    return false;
}



