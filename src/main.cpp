#include <iostream>
#include <gravity/game.hpp>
#include <SFML/Graphics.hpp>
#include <Eigen/Dense>



int main()
{
    sf::Vector2f viewCenter(0.f, 0.f);
    sf::Vector2f resolution(1920.f, 1080.f);

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Gravity!");
    window.setFramerateLimit(60);
    const float ZoomAmount{1.02f};

    sf::View view(viewCenter, resolution);
    view.zoom(20.2f);

    // auto g = Game();
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
    //     composeVec2(5000.0, 5000.0),
    //     composeVec2(-25.0, -1.0),
    //     composeVec2(0.0, 0.0)
    // );


    auto g = Game();
    g.addObject(1000.0, 50000.0, sf::Color::Red,
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0),
        composeVec2(0.0, 0.0),
        true
    );

    g.addObject(150.0, 150.0, sf::Color::Green,
        composeVec2(0.0, -5000.0),
        composeVec2(100.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(150.0, 150.0, sf::Color::Green,
        composeVec2(6000.0, 0.0),
        composeVec2(0.0, 100.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(150.0, 150.0, sf::Color::Green,
        composeVec2(0.0, 5000.0),
        composeVec2(-100.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(150.0, 150.0, sf::Color::Green,
        composeVec2(-5000.0, 0.0),
        composeVec2(0.0, -100.0),
        composeVec2(0.0, 0.0)
    );

    g.addObject(150.0, 150.0, sf::Color::Green,
        composeVec2(0.0, -7000.0),
        composeVec2(100.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(150.0, 150.0, sf::Color::Green,
        composeVec2(10000.0, 0.0),
        composeVec2(0.0, 80.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(150.0, 150.0, sf::Color::Green,
        composeVec2(0.0, 7000.0),
        composeVec2(-90.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(150.0, 150.0, sf::Color::Green,
        composeVec2(-7000.0, 0.0),
        composeVec2(0.0, -100.0),
        composeVec2(0.0, 0.0)
    );

    g.addObject(250.0, 250.0, sf::Color::Yellow,
        composeVec2(-15000.0, 0.0),
        composeVec2(0.0, -60.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(250.0, 250.0, sf::Color::Yellow,
        composeVec2(0.0, -20000.0),
        composeVec2(40.0, 0.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(250.0, 250.0, sf::Color::Yellow,
        composeVec2(17500.0, 0.0),
        composeVec2(0.0, 70.0),
        composeVec2(0.0, 0.0)
    );
    g.addObject(250.0, 250.0, sf::Color::Yellow,
        composeVec2(0.0, 19000.0),
        composeVec2(-90.0, 0.0),
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

