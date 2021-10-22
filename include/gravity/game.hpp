#include <iostream>
#include <SFML/Graphics.hpp>
#include <gravity/object.hpp>
#include <memory>
#include <gravity/physicsUtils.hpp>




class Game
{

public:
    Game(){};
    ~Game(){};

    // Include object (2D circle) with defined radius,
    // colour, init position, velocity and acceleration
    auto addObject(
        const float& radius,
        const float& mass,
        const sf::Color& color,
        const Vec2& position,
        const Vec2& velocity,
        const Vec2& acceleration,
        const bool& isStatic = false
    ) -> void;

    // Takes objects positions, calculates accel from
    // gravity force, then velocity and new positions
    // every iteration 
    auto computePhysics() -> void;

    // After physics is computed, this method is called
    // to redraw the scene
    auto drawObjects(sf::RenderWindow& window) -> void;

    // Panning mechanics
    auto panningMechanics(
        sf::View& view,
        sf::Vector2f& viewCenter
    ) -> void;

    // Function to handle collision between objects
    auto handleCollision(
        Object& a, 
        Object& b
    ) -> std::tuple<Vec2, Vec2>;

    // Function to handle objects overlapping, ignoring
    // physics, just shifting objects 
    auto handleOverlapping(
        Object& a,
        Object& b,
        float overlap
    ) -> std::tuple<Vec2, Vec2>;

private:

    // Vector is used to store pointers to 
    // every created object
    std::vector<Object> objects;

};