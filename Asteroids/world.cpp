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
