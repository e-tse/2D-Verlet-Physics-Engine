// Ball.h
// Last Update: 12/20/2022
// Author: Ethan Tse
// Defines the Ball class
#pragma once
#include "Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

//Constructor
Ball::Ball()
{
    setPosition(sf::Vector2f(0.0f, 0.0f));
    setVelocity(sf::Vector2f(0.0f, 0.0f));
    setRadius(5.0f);
    setColor(sf::Color::White);
    setForce(sf::Vector2f(0.0f, 0.0f));
    setMass(5.0f);
    setCoefficientOfRestitution(1.0f);
    
};

//Constructor with parameters
Ball::Ball(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass, sf::Color color)
{
    setPosition(position);
    setVelocity(velocity);
    setRadius(radius);
    setColor(color);
    setForce(sf::Vector2f(0.0f, 0.0f));
    setMass(mass);
    setCoefficientOfRestitution(1.0f);
};

Ball::Ball(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass, sf::Vector2f force, float coefficientOfRestitution, sf::Color color){
    setPosition(position);
    setVelocity(velocity);
    setRadius(radius);
    setColor(color);
    setForce(force);
    setMass(mass);
    setCoefficientOfRestitution(coefficientOfRestitution);

};

//Destructor
Ball::~Ball(){

};

//Update function
void Ball::update(float dt){
    
    //using verlet integration, update position
    position.x += velocity.x * dt + 0.5 * force.x * dt * dt / mass;
    position.y += velocity.y * dt + 0.5 * force.y * dt * dt / mass;

    //using verlet integration, update velocity
    velocity.x += force.x * dt / mass;
    velocity.y += force.y * dt / mass;
}

//Getters
sf::Vector2f Ball::getPosition(){
    return position;
}
float Ball::getRadius(){
    return radius;
};
sf::Color Ball::getColor(){
    return color;
};

sf::Vector2f Ball::getForce(){
    return force;
};
float Ball::getMass(){
    return mass;
};
sf::Vector2f Ball::getVelocity(){
    return velocity;
};

float Ball::getCoefficientOfRestitution(){
    return coefficientOfRestitution;
};

float Ball::getInverseMass(){
    return inverse_mass;
};



//Setters
void Ball::setPosition(sf::Vector2f _position){
    position = _position;
};
void Ball::setRadius(float _radius){
    radius = _radius;
};
void Ball::setColor(sf::Color _color){
    color = _color;
};
void Ball::setForce(sf::Vector2f _force){  
    force = _force;
};
void Ball::setMass(float _mass){
    mass = _mass;
    inverse_mass = 1.0f / mass;
};
void Ball::setVelocity(sf::Vector2f _velocity){
    velocity = _velocity;
};

void Ball::setCoefficientOfRestitution(float _coefficientOfRestitution){
    coefficientOfRestitution = _coefficientOfRestitution;
};

void Ball::applyForce(sf::Vector2f _force){
    force.x += _force.x;
    force.y += _force.y;
};


std::string Ball::toString(){
    return "Position: " + std::to_string(position.x) + ", " + std::to_string(position.y) + 
    ", Velocity: " + std::to_string(velocity.x) + ", " + std::to_string(velocity.y) + 
    ", Radius: " + std::to_string(radius) + 
    ", Mass: " + std::to_string(mass) + 
    ", Color: " + std::to_string(color.r) + ", " + std::to_string(color.g) + ", " + std::to_string(color.b) + ", " + std::to_string(color.a) + 
    ", Force: " + std::to_string(force.x) + ", " + std::to_string(force.y);
    }

