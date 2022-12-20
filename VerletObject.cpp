// VerletObject.h
// Date: 12/04/2022
// Author: Ethan Tse
// Defines the VerletObject class
#pragma once
#include "VerletObject.h"
#include "common.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

//Constructor
VerletObject::VerletObject()
{
    shape = sf::CircleShape(radius, 100);
    SetPosition(sf::Vector2f(0.0f, 0.0f));
    SetVelocity(sf::Vector2f(0.0f, 0.0f));
    SetRadius(5.0f);
    SetColor(sf::Color::White);
    SetForce(sf::Vector2f(0.0f, 0.0f));
    SetMass(5.0f);
    
};

//Constructor with parameters
VerletObject::VerletObject(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass, sf::Color color)
{
    shape = sf::CircleShape(radius, 100);
    SetPosition(position);
    SetVelocity(velocity);
    SetRadius(radius);
    SetColor(color);
    SetForce(sf::Vector2f(0.0f, 0.0f));
    SetMass(mass);

};

VerletObject::VerletObject(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass, sf::Vector2f force, sf::Color color){
    shape = sf::CircleShape(radius, 100);
    SetPosition(position);
    SetVelocity(velocity);
    SetRadius(radius);
    SetColor(color);
    SetForce(force);
    SetMass(mass);
    

};

//Destructor
VerletObject::~VerletObject(){

};

//Update function
void VerletObject::Update(float dt){
    
    //using verlet integration, update position
    position.x += velocity.x * dt + 0.5 * force.x * dt * dt / mass;
    position.y += velocity.y * dt + 0.5 * force.y * dt * dt / mass;
    shape.setPosition(position);
    //using verlet integration, update velocity
    velocity.x += force.x * dt / mass;
    velocity.y += force.y * dt / mass;
}

//Draw function
void VerletObject::Draw(sf::RenderWindow &window){
    window.draw(shape);
};

//Getters
sf::Vector2f VerletObject::GetPosition(){
    return position;
}
float VerletObject::GetRadius(){
    return radius;
};
sf::Color VerletObject::GetColor(){
    return color;
};

sf::Vector2f VerletObject::GetForce(){
    return force;
};
float VerletObject::GetMass(){
    return mass;
};
sf::Vector2f VerletObject::GetVelocity(){
    return velocity;
};



//Setters
void VerletObject::SetPosition(sf::Vector2f _position){
    position = _position;
    shape.setPosition(_position);
};
void VerletObject::SetRadius(float _radius){
    radius = _radius;
    shape.setRadius(_radius);
    shape.setOrigin(_radius, _radius);
};
void VerletObject::SetColor(sf::Color _color){
    color = _color;
    shape.setFillColor(_color);
};
void VerletObject::SetForce(sf::Vector2f _force){  
    force = _force;
};
void VerletObject::SetMass(float _mass){
    mass = _mass;
};
void VerletObject::SetVelocity(sf::Vector2f _velocity){
    velocity = _velocity;
};

void VerletObject::ApplyForce(sf::Vector2f _force){
    force.x += _force.x;
    force.y += _force.y;
};


std::string VerletObject::ToString(){
    return "Position: " + std::to_string(position.x) + ", " + std::to_string(position.y) + 
    ", Velocity: " + std::to_string(velocity.x) + ", " + std::to_string(velocity.y) + 
    ", Radius: " + std::to_string(radius) + 
    ", Mass: " + std::to_string(mass) + 
    ", Color: " + std::to_string(color.r) + ", " + std::to_string(color.g) + ", " + std::to_string(color.b) + ", " + std::to_string(color.a) + 
    ", Force: " + std::to_string(force.x) + ", " + std::to_string(force.y);
    }