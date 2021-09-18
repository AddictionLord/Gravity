#pragma once
#include <iostream>
#include <gravity/common.hpp>
#include <SFML/Graphics.hpp>




class Game
{

public:
    Game();
    ~Game();

    // Include object (2D circle) with defined radius,
    // colour, init position, velocity and acceleration
    void addObject(
        const float& radius,
        const sf::Color& color,
        const Vec2& position,
        const Vec2& velocity,
        const Vec2& acceleration
    );

    // Takes objects positions, calculates accel from
    // gravity force, then velocity and new positions
    // every iteration 
    void computePhysics();

    // After physics is computed, this method is called
    // to redraw the scene
    void drawObjects();


private:

    // Vector is used to store pointers to 
    // every created object
    std::vector<Object*> objects;

};