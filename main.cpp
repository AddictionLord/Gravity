#include <iostream>
#include <gravity/game.hpp>
#include <SFML/Graphics.hpp>
#include <Eigen/Dense>



int main()
{ 
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Gravity!");
    auto g = Game();
    g.addObject(20.0, 1, sf::Color::Green,
        composeVec2(150.0, 150.0),
        composeVec2(0.0, .1),
        composeVec2(0.0, 0.0)
    );
    g.addObject(20.0, 2, sf::Color::Red,
        composeVec2(1650, 150.0),
        composeVec2(-.1, .0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(20.0, 1, sf::Color::Blue,
        composeVec2(950.0, 1000.0),
        composeVec2(0.1, -.1),
        composeVec2(0.0, 0.0)
    );
    // g.addObject(10.0, 50, sf::Color::White,
    //     composeVec2(950.0, 500.0),
    //     composeVec2(0.0, 0.0),
    //     composeVec2(0.0, 0.0),
    //     true
    // );


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        g.computePhysics();

        window.clear();
        g.drawObjects(window);
        window.display();
    }

    return 0;
}

