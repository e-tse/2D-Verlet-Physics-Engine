// Container.cpp
// Created by: Ethan Tse
// Last Update: 12/20/2022
// Description: Defines the Container class
#include "Container.h"
#include "Ball.h"
#include "VectorMath.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>

//Constructor
Container::Container()
{
    
};

//Destructor
Container::~Container()
{
};

//Update function
void Container::update(float dt)
{
    for (int i = 0; i < balls_vector.size(); i++)
    {
        balls_vector[i].update(dt);
    }
};

//draw
void Container::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < balls_vector.size(); i++)
    {
        balls_vector[i].draw(window);
    }
};

//Add ball function
void Container::addBall(Ball ball)
{
    balls_vector.push_back(ball);
};

//Getters
std::vector<Ball> Container::getBallVector()
{
    return balls_vector;
};

//toString function
std::string Container::toString()
{
    std::string output = "";
    for (int i = 0; i < balls_vector.size(); i++)
    {
        output += balls_vector[i].toString();
    }
    return output;
};



inline bool Container::isColliding(Ball a, Ball b)
{
    float r = a.getRadius() + b.getRadius();
    r *= r;
    return (r > VectorMath::distanceSquared(a.getPosition(), b.getPosition()));

};

void Container::checkCollisions(){
    for (int i = 0; i < balls_vector.size(); i++)
    {
        for (int j = 0; j < balls_vector.size(); j++)
        {
            if(i == j){ //Same ball
                continue;
            }

            if (isColliding(balls_vector[i], balls_vector[j]))
            {
                resolveCollision(balls_vector[i], balls_vector[j]);

            }
        }
    }               
}

inline void Container::resolveCollision(Ball& a, Ball& b){
    //Resolve collions
    sf::Vector2f normal = a.getPosition() - b.getPosition();
    normal = VectorMath::normalize(normal);

}