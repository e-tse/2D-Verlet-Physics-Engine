
#include <iostream>
#include <SFML/Graphics.hpp>
#include "VerletObject.h"
#include "common.h"
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    VerletObject one;
    std::cout << one.ToString() << std::endl;
    // one.SetRadius(10.0f);
    // std::cout << one.ToString() << std::endl;
    // one.SetPosition(sf::Vector2f(-5.0f, -5.0f));
    one.SetVelocity(sf::Vector2f(50.0f, 0.0f));
    one.SetForce(sf::Vector2f(0.0f, 9.8f*5.0f));

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
        one.Draw(window); 
        window.display();
        one.Update(dt);
    }
// std::cout << one.ToString() << std::endl;
    return 0;
}