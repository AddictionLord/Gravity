#include <iostream>
#include <gravity/game.hpp>
#include <SFML/Graphics.hpp>
#include <Eigen/Dense>



int main()
{
    sf::Vector2f viewCenter(0.f, 0.f);
    sf::Vector2f resolution(1920.f, 1080.f);

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Gravity!");
    window.setFramerateLimit(120);
    const float ZoomAmount{1.02f};

    sf::View view(viewCenter, resolution);

    auto g = Game();
    // g.addObject(30.0, 15.0, sf::Color::Green,
    //     composeVec2(0.0, 0.0),
    //     composeVec2(6.0, -2.5),
    //     composeVec2(0.0, 0.0)
    // );
    // g.addObject(30.0, 15.0, sf::Color::Red,
    //     composeVec2(1000.0, 0.0),
    //     composeVec2(6.0, 2.5),
    //     composeVec2(0.0, 0.0)
    // );

    g.addObject(30.0, 15.0, sf::Color::Green,
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(30.0, 15.0, sf::Color::Red,
        composeVec2(1000.0, 0.0),
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0)
    );

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            // Zoom mechanics 
            case sf::Event::MouseWheelScrolled:
                if (event.mouseWheelScroll.delta >= 1)
                {
                    view.zoom(1.f / ZoomAmount);
                }
                if (event.mouseWheelScroll.delta <= -1)
                {
                    view.zoom(1.02f);
                }
            }
        }

        g.panningMechanics(view, viewCenter);
        g.computePhysics();

        window.clear();
        window.setView(view);
        g.drawObjects(window);
        window.display();
    }

    return 0;
}

