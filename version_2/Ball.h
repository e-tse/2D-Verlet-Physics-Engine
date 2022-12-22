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
        Ball(sf::Vector2f position_, sf::color color_)

        //Destructor
        ~Ball();
        //Update function
        void update(float dt);
        //Getters
        
        sf::Vector2f getPosition();
        sf::Vector2f getVelocity();
        float getRadius();
        sf::Color getColor();
        sf::Vector2f getForce();
        float getMass();
        float getInverseMass();
        float getCoefficientOfRestitution();

        //Setters
        void setPosition(sf::Vector2f _position);
        void setRadius(float _radius);
        void setColor(sf::Color _color);
        void setForce(sf::Vector2f _force);
        void setMass(float _mass);
        void setVelocity(sf::Vector2f _velocity);
        void setCoefficientOfRestitution(float _coefficientOfRestitution);
    

        void applyForce(sf::Vector2f force);


        std::string toString();    

    //Private variables and functions
    private:
        float coefficientOfRestitution;
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f force;
        float radius;
        float mass;
        float inverse_mass;
        sf::Color color;
        sf::CircleShape shape;

};

