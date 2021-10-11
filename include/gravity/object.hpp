#include <gravity/common.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>



class Object
{
public:
    Object(
        const float& radius = 20.f,
        const float& mass = 20.0,
        sf::Color color = sf::Color::Green
    );
    //~Object(){};

    // Setting position, velocity and acceleration
    auto setPosition(Vec2 pos) -> void;
    auto setVelocity(Vec2 vel) -> void;
    auto setAcceleration(Vec2 accel) -> void;

    // Get vector representing position, velocity
    // and acceleration
    auto getPosition() -> Vec2;
    auto getVelocity() -> Vec2;
    auto getAcceleration() -> Vec2;

    // returns mass of the object
    auto getMass() -> float&;

    // returns reference to shape object for drawing 
    auto getShape() -> sf::CircleShape&;

    // object is not moving
    auto makeStatic() -> void;

    auto getStatic() -> bool;

    auto isInCollision(Object& otherObject) -> bool;


protected:
    float mass;
    float radius;
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;


private:
    bool isStatic;
    sf::CircleShape shape;  

};