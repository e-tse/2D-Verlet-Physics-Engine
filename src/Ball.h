// Ball.h
// Last Update: 12/20/2022
// Author: Ethan Tse
// Defines the Ball class
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

//Create a class called VerletObject with 
class Ball
{
    //Public variables and functions
    public:
        //Constructor
        Ball();
        //Constructor with parameters
        Ball(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass,  sf::Color color);
        Ball(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass, sf::Vector2f force, sf::Color color);
        //Destructor
        ~Ball();
        //Update function
        void update(float dt);
        //Draw function
        void draw(sf::RenderWindow &window);
        //Getters
        sf::Vector2f getPosition();
        sf::Vector2f getVelocity();
        float getRadius();
        sf::Color getColor();
        sf::Vector2f getForce();
        float getMass();

        //Setters
        void setPosition(sf::Vector2f position);
        void setRadius(float radius);
        void setColor(sf::Color color);
        void setForce(sf::Vector2f force);
        void setMass(float mass);
        void setVelocity(sf::Vector2f velocity);
    

        void applyForce(sf::Vector2f force);


        std::string toString();    

    //Private variables and functions
    private:

        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f force;
        float radius;
        float mass;
        sf::Color color;
        sf::CircleShape shape;

};

