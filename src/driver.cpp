// driver.cpp
// Created by: Ethan Tse
// Last Update: 12/20/2022
// Description: Driver file for the simulator
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include <string>
#include "Container.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    Ball one;
    std::cout << one.toString() << std::endl;
    // one.SetRadius(10.0f);
    // std::cout << one.ToString() << std::endl;
    // one.SetPosition(sf::Vector2f(-5.0f, -5.0f));
    one.setVelocity(sf::Vector2f(50.0f, 0.0f));
    one.setForce(sf::Vector2f(0.0f, 9.8f*5.0f));

    Container container;
    container.addBall(one);

    float dt = 0.01f;
    while (window.isOpen())
    {
        //pause for dt seconds
        sf::sleep(sf::seconds(dt));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                
                window.close();
        }

        window.clear();
        container.draw(window); 
        window.display();
        container.update(dt);
    }
// std::cout << one.ToString() << std::endl;
    return 0;
}