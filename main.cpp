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
    // g.addObject(150.0, 150.0, sf::Color::Green,
    //     composeVec2(0.0, 0.0),
    //     composeVec2(0.0, 0.0),
    //     composeVec2(0.0, 0.0)
    // );
    // g.addObject(150.0, 150.0, sf::Color::Red,
    //     composeVec2(1000.1, 0.0),
    //     composeVec2(-1.0, 0.0),
    //     composeVec2(0.0, 0.0)
    // );
    // g.addObject(150.0, 150.0, sf::Color::Red,
    //     composeVec2(-1000.1, 0.0),
    //     composeVec2(2.0, 0.0),
    //     composeVec2(0.0, 0.0)
    // );
    //     g.addObject(300.0, 3000.0, sf::Color::Red,
    //     composeVec2(5000, 5000.0),
    //     composeVec2(-1.0, -1.0),
    //     composeVec2(0.0, 0.0)
    // );


    // g.addObject(150.0, 150.0, sf::Color::Green,
    //     composeVec2(0.0, 0.0),
    //     composeVec2(0.0, 0.0),
    //     composeVec2(0.0, 0.0)
    // );
    // g.addObject(150.0, 150.0, sf::Color::Red,
    //     composeVec2(320.1, 0.0),
    //     composeVec2(0.0, 0.0),
    //     composeVec2(0.0, 0.0)
    // );

    g.addObject(1000.0, 50000.0, sf::Color::Yellow,
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(50.0, 50.0, sf::Color::Blue,
        composeVec2(20000, 0.0),
        composeVec2(0.0, 10.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(500.0, 500.0, sf::Color::Green,
        composeVec2(-20000, 0.0),
        composeVec2(0.0, 10.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(100.0, 100.0, sf::Color::Red,
        composeVec2(0.0, 20000),
        composeVec2(2.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(1000.0, 1000.0, sf::Color::Magenta,
        composeVec2(-20000, 10000.0),
        composeVec2(20.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(1000.0, 1000.0, sf::Color::Cyan,
        composeVec2(10000, 10000.0),
        composeVec2(-30.0, -30.0),
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

