#include <iostream>
#include <gravity/game.hpp>
#include <SFML/Graphics.hpp>
#include <Eigen/Dense>



int main()
{
    sf::Vector2f viewCenter(960.f, 540.f);
    sf::Vector2f resolution(1920.f, 1080.f);

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Gravity!");
    window.setFramerateLimit(120);
    const float ZoomAmount{1.02f};

    sf::View view(viewCenter, resolution);

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
    g.addObject(10.0, 1, sf::Color::White,
        composeVec2(950.0, 500.0),
        composeVec2(0.0, -.2),
        composeVec2(0.0, 0.0)
    );


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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            view.setCenter(viewCenter.x -= 15, viewCenter.y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            view.setCenter(viewCenter.x += 15, viewCenter.y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            view.setCenter(viewCenter.x, viewCenter.y -= 15);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            view.setCenter(viewCenter.x, viewCenter.y += 15);

        g.computePhysics();

        window.clear();
        window.setView(view);
        g.drawObjects(window);
        window.display();
    }

    return 0;
}

