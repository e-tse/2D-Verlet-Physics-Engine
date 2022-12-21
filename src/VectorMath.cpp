// VectorMath.cpp
// Date: 12/04/2022
// Author: Ethan Tse
// Defines math for vectors

#include "VectorMath.h"
#include <math.h>

float VectorMath::distanceSquared(sf::Vector2f a, sf::Vector2f b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
};

float VectorMath::distance(sf::Vector2f a, sf::Vector2f b)
{
    return sqrt(VectorMath::distanceSquared(a, b));
};

sf::Vector2f VectorMath::normalize(sf::Vector2f a)
{
    float length = VectorMath::distance(a, sf::Vector2f(0.0f, 0.0f));
    return sf::Vector2f(a.x / length, a.y / length);
};

float VectorMath::dotProduct(sf::Vector2f a, sf::Vector2f b)
{
    return a.x * b.x + a.y * b.y;
};