#include <iostream>
#include <gravity/game.hpp>
#include <SFML/Graphics.hpp>
#include <Eigen/Dense>



int main()
{ 
    sf::RenderWindow window(sf::VideoMode(700, 700), "Gravity!");
    auto g = Game();
    g.addObject(20.0, 1, sf::Color::Green,
        composeVec2(150.0, 150.0),
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(20.0, 2, sf::Color::Red,
        composeVec2(600.0, 600.0),
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0)
    );

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




// int main()
// { 
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }