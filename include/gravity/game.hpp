#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <gravity/object.hpp>
#include <memory>
#include <gravity/physicsUtils.hpp>




class Game
{

public:
    Game()
    {
        if (!font.loadFromFile("../fonts/Pixellettersfull-BnJ5.ttf"))
        {
            std::cerr << "Error while loading font" << std::endl;
        }

        std::stringstream ss;
        ss << "Time speed: " << (double)dt*frameRate << "x";

        text.setFont(font); // font est un sf::Font
        text.setString(ss.str());
        text.setCharacterSize(40);
        text.setFillColor(sf::Color::White);
        text.setOrigin(text.getLocalBounds().width/2. + 850, text.getLocalBounds().height/2. + 540);
    };

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
    // every iteration (Euler numeric method)
    auto computePhysics() -> void;

    // After physics is computed, this method is called
    // to redraw the scene
    auto drawGraphics(sf::RenderWindow& window) -> void;

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

    // Used to control time dilatation/contraction 
    // via Game::speedCoef variable
    auto timeControl() -> void;

    int frameRate;
    double dt;
    sf::Text text;


private:

    // Vector is used to store pointers to 
    // every created object
    std::vector<Object> objects;
    sf::Font font;

};