#include <gravity/object.hpp>



//--------------------------------------------
Object::Object(
    const float& radius,
    const float& mass,
    sf::Color color
)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
}


//--------------------------------------------
auto Object::setPosition(Vec2 pos) -> void
{
    position = pos;
}

//--------------------------------------------
auto Object::setVelocity(Vec2 vel) -> void
{
    velocity = vel;
}

//--------------------------------------------
auto Object::setAcceleration(Vec2 accel) -> void
{
    acceleration = accel;
}


//--------------------------------------------
auto Object::getPosition() -> Vec2
{
    return position;
}

//--------------------------------------------
auto Object::getVelocity() -> Vec2
{
    return velocity;
}

//--------------------------------------------
auto Object::getAcceleration() -> Vec2
{
    return acceleration;
}

//--------------------------------------------
auto Object::getMass() -> float&
{
    return mass;
}
