// VerletObject.h
// Date: 12/04/2022
// Author: Ethan Tse
// Defines the VerletObject class
#pragma once
#include "common.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

//Create a class called VerletObject with 
class VerletObject
{
    //Public variables and functions
    public:
        //Constructor
        VerletObject();
        //Constructor with parameters
        VerletObject(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass,  sf::Color color);
        VerletObject(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass, sf::Vector2f force, sf::Color color);
        //Destructor
        ~VerletObject();
        //Update function
        void Update(float dt);
        //Draw function
        void Draw(sf::RenderWindow &window);
        //Getters
        sf::Vector2f GetPosition();
        sf::Vector2f GetVelocity();
        float GetRadius();
        sf::Color GetColor();
        sf::Vector2f GetForce();
        float GetMass();
        sf::Vector2f GetGravityAcceleration();
        bool IsGravityEnabled();
        //Setters
        void SetPosition(sf::Vector2f position);
        void SetRadius(float radius);
        void SetColor(sf::Color color);
        void SetForce(sf::Vector2f force);
        void SetMass(float mass);
        void SetVelocity(sf::Vector2f velocity);
    

        void ApplyForce(sf::Vector2f force);


        std::string ToString();    

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

