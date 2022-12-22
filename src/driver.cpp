// driver.cpp
// Created by: Ethan Tse
// Last Update: 12/20/2022
// Description: Driver file for the simulator
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include <string>
#include "Container.h"
#include "common.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

    // Ball one;
    // Ball two;
    // // std::cout << one.toString() << std::endl;
    // one.setRadius(20.0f);
    // // std::cout << one.ToString() << std::endl;
    // one.setPosition(sf::Vector2f(250.0f, 250.0f));

    // one.setPosition(sf::Vector2f(20.0f, 20.0f));
    // two.setPosition(sf::Vector2f(250.0f, 20.0f));

    // one.setVelocity(sf::Vector2f(50.0f, 0.0f));
    // two.setVelocity(sf::Vector2f(-50.0f, 0.0f));
    // one.setColor(sf::Color::Red);
    // one.setMass(100.0f);
    // one.setForce(sf::Vector2f(0.0f, 9.8f*10000.0f));
    // // one.setCoefficientOfRestitution(0.5f);
    Container container;
    // container.addBall(one);
    // container.addBall(two);

    int num_balls = 30;
    for (int i = 0; i < num_balls; i++)
    {
        for(int ii = 0; ii < num_balls; ii++){
            Ball new_ball;
            //create a random float between -100 and 100 for the x and y velocity

            float gap = WINDOW_HEIGHT / (num_balls + 1);

            new_ball.setRadius(2.5);
            new_ball.setPosition(sf::Vector2f(gap + gap * i, gap + gap * ii));
            new_ball.setVelocity(sf::Vector2f(100000.0f - (float)rand() / (float)RAND_MAX * 200000.0f, 100000.0f - (float)rand() / (float)RAND_MAX * 200000.0f));

            //create new sf color that is random
            sf::Color new_color;
            new_color.r = (sf::Uint8)(rand() % 255);
            new_color.g = (sf::Uint8)(rand() % 255);
            new_color.b = (sf::Uint8)(rand() % 255);
            new_color.a = 255;
            new_ball.setColor(new_color);
            new_ball.setMass(10.0f);
            container.addBall(new_ball);

        }
    }
    
    float dt = 0.001f;
    float render_dt = 0.00001f;
    float physics_dt = 0.0001f;
    float dt_accumulator = 0.0f;
    while (window.isOpen())
    {
        //pause for dt seconds
        sf::sleep(sf::seconds(render_dt));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                
                window.close();
        }


        //update physics
        dt_accumulator += render_dt;
        while (dt_accumulator >= physics_dt)
        {
            container.update(physics_dt);
            dt_accumulator -= physics_dt;
        }

        //render
        while (dt_accumulator >= physics_dt)
        {
            container.update(physics_dt);
            dt_accumulator -= physics_dt;
        }

        //render



        window.clear();
        container.render(window); 
        window.display();

    }
// std::cout << one.ToString() << std::endl;
    return 0;
}