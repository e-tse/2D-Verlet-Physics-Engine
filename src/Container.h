// Contianer.h
// Created by: Ethan Tse
// Last Update: 12/20/2022
// Description: Defines the Container class
#pragma once
#include "Ball.h"
#include "VectorMath.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

//A container class to hold ball objects
class Container
{
    public:
        //Constructor
        Container();
        //Destructor
        ~Container();
        //Update function
        void update(float dt);
        //draw
        void draw(sf::RenderWindow &window);
        //Add ball function
        void addBall(Ball ball);
        //Getters
        std::vector<Ball> getBallVector();

        //collisions
        void checkCollisions();
    
        
        //toString function
        std::string toString();
    private:
        //vector of balls
        std::vector<Ball> balls_vector;
        inline bool isColliding(Ball a, Ball b);
        inline void resolveCollision(Ball &a, Ball &b);


};