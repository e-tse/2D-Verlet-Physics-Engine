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
#include "common.h"
#include "omp.h"

//Constructor
Container::Container()
{
    enableBorders();
};

//Destructor
Container::~Container()
{
};

//Update function
void Container::update(float dt)
{
    #pragma omp parallel
    {
        int id, nthreads;
        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();

        for (int i = id; i < balls_vector.size(); i+=nthreads)
        {
            balls_vector[i].update(dt);
        }
        checkCollisions(id, nthreads);

        if(bordersEnabled){
            bounceBorders(id, nthreads);
        }
    }
};

void Container::bounceBorders(int id, int nthreads){
    for (int i = id; i < balls_vector.size(); i+=nthreads)
    {
        if(balls_vector[i].getPosition().x - balls_vector[i].getRadius() < 0){
            balls_vector[i].setPosition(sf::Vector2f(balls_vector[i].getRadius(), balls_vector[i].getPosition().y));
            balls_vector[i].setVelocity(sf::Vector2f(-balls_vector[i].getVelocity().x * balls_vector[i].getCoefficientOfRestitution(), balls_vector[i].getVelocity().y));
        }
        if(balls_vector[i].getPosition().x + balls_vector[i].getRadius() > WINDOW_WIDTH){
            balls_vector[i].setPosition(sf::Vector2f(WINDOW_WIDTH - balls_vector[i].getRadius(), balls_vector[i].getPosition().y));
            balls_vector[i].setVelocity(sf::Vector2f(-balls_vector[i].getVelocity().x * balls_vector[i].getCoefficientOfRestitution(), balls_vector[i].getVelocity().y));
        }
        if(balls_vector[i].getPosition().y - balls_vector[i].getRadius() < 0){
            balls_vector[i].setPosition(sf::Vector2f(balls_vector[i].getPosition().x, balls_vector[i].getRadius()));
            balls_vector[i].setVelocity(sf::Vector2f(balls_vector[i].getVelocity().x, -balls_vector[i].getVelocity().y * balls_vector[i].getCoefficientOfRestitution()));
        }
        if(balls_vector[i].getPosition().y + balls_vector[i].getRadius() > WINDOW_HEIGHT){
            balls_vector[i].setPosition(sf::Vector2f(balls_vector[i].getPosition().x, WINDOW_HEIGHT - balls_vector[i].getRadius()));
            balls_vector[i].setVelocity(sf::Vector2f(balls_vector[i].getVelocity().x, -balls_vector[i].getVelocity().y * balls_vector[i].getCoefficientOfRestitution()));
        }
    }   
}


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

bool Container::isBordersEnabled()
{
    return bordersEnabled;
};

//Setters
void Container::setBordersEnabled(bool _bordersEnabled)
{
    bordersEnabled = _bordersEnabled;
};

void Container::toggleBordersEnabled()
{
    bordersEnabled = !bordersEnabled;
};

void Container::enableBorders()
{
    bordersEnabled = true;
};

void Container::disableBorders()
{
    bordersEnabled = false;
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



bool Container::isColliding(Ball a, Ball b)
{
    float r = a.getRadius() + b.getRadius();
    r *= r;
    return (r > VectorMath::distanceSquared(a.getPosition(), b.getPosition()));

};

void Container::checkCollisions(int id, int nthreads){
    for (int i = id; i < balls_vector.size(); i+=nthreads)
    {
        //can do i+1 to avoid checking the same ball twice
        for (int j = i+1; j < balls_vector.size(); j++)
        {
            if (isColliding(balls_vector[i], balls_vector[j]))
            {
                resolveCollision(balls_vector[i], balls_vector[j]);

            }
        }
    }          
}

void Container::resolveCollision(Ball& a, Ball& b){
    //Resolve collions
    sf::Vector2f collision_normal = a.getPosition() - b.getPosition();
    collision_normal = VectorMath::normalize(collision_normal);

    //move balls out of each other
    float penetration = a.getRadius() + b.getRadius() - VectorMath::distance(a.getPosition(), b.getPosition());
    a.setPosition(a.getPosition() + collision_normal * penetration * 0.5f);
    b.setPosition(b.getPosition() - collision_normal * penetration * 0.5f);

    //Equation taken from 
    //https://research.ncl.ac.uk/game/mastersdegree/gametechnologies/physicstutorials/5collisionresponse/Physics%20-%20Collision%20Response.pdf
    float e = a.getCoefficientOfRestitution() * b.getCoefficientOfRestitution();
    // e=0.0f;
    sf::Vector2f relativeVelocity = a.getVelocity() - b.getVelocity();
    float j = -(1 + e) * VectorMath::dotProduct(relativeVelocity, collision_normal);
    j /= a.getInverseMass() + b.getInverseMass();

    sf::Vector2f impulse = collision_normal * j;
    a.setVelocity(a.getVelocity() + impulse * a.getInverseMass());
    b.setVelocity(b.getVelocity() - impulse * b.getInverseMass());

}

//Render
void Container::render(sf::RenderWindow& window){

    sf::CircleShape circle(1.0f);
    circle.setPointCount(32);
    circle.setOrigin(1.0f, 1.0f);
    //iterate through balls and draw them
    for (int i = 0; i < balls_vector.size(); i++)
    {
        circle.setPosition(balls_vector[i].getPosition());
        circle.setRadius(balls_vector[i].getRadius());
        circle.setFillColor(balls_vector[i].getColor());
        window.draw(circle);
    }
};