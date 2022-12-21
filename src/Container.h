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

        
    
        
        //toString function
        std::string toString();
    private:
        //vector of balls
        std::vector<Ball> balls_vector;
        
        //collisions
        void checkCollisions();
        bool isColliding(Ball a, Ball b);
        void resolveCollision(Ball &a, Ball &b);


};