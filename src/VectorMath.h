// VectorMath.h
// Date: 12/04/2022
// Author: Ethan Tse
// Defines math for vectors
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
namespace VectorMath{
    float distanceSquared(sf::Vector2f a, sf::Vector2f b);
    float distance(sf::Vector2f a, sf::Vector2f b);
    sf::Vector2f normalize(sf::Vector2f a);
}


