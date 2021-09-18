#include <iostream>
#include <SFML/Graphics.hpp>
#include <gravity/object.hpp>
#include <memory>




class Game
{

public:
    Game();
    ~Game();

    // Include object (2D circle) with defined radius,
    // colour, init position, velocity and acceleration
    auto addObject(
        const float& radius,
        const sf::Color& color,
        const Vec2& position,
        const Vec2& velocity,
        const Vec2& acceleration
    ) -> void;

    // Takes objects positions, calculates accel from
    // gravity force, then velocity and new positions
    // every iteration 
    auto computePhysics() -> void;

    // After physics is computed, this method is called
    // to redraw the scene
    auto drawObjects() -> void;


private:

    // Vector is used to store pointers to 
    // every created object
    std::vector<std::shared_ptr<Object>> objects;

};