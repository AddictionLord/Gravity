#include <gravity/object.hpp>



//--------------------------------------------
Object::Object(
    const float& radius,
    const float& mass,
    sf::Color color
)
{
    this->radius = radius;
    this->mass = mass;
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);
}


//--------------------------------------------
auto Object::setPosition(Vec2 pos) -> void
{
    position = pos;
    if (!isStatic)
    {
        shape.setPosition(position(0), position(1));
    }
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

//--------------------------------------------
auto Object::getShape() -> sf::CircleShape&
{
    return shape;
}

//--------------------------------------------
auto Object::makeStatic() -> void
{
    isStatic = true;
}

//--------------------------------------------
auto Object::getStatic() -> bool
{
    return isStatic;
}

//--------------------------------------------
auto Object::isInCollision(Object& otherObject) -> bool
{
    auto squared_distance = computeSquaredDistanceBetweenVectors(
        this->position, otherObject.position
    );
    auto squared_radiuses = std::pow(this->radius + otherObject.radius, 2);

    return (squared_radiuses >= squared_distance);
}

//--------------------------------------------
auto Object::overlaps(Object& otherObject) -> float
{
    auto distance = computeDistanceBetweenVectors(this->position, otherObject.position);
    auto radiuses = this->radius + otherObject.radius;

    return (radiuses - distance) / 2;
}