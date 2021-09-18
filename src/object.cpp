#include <gravity/object.hpp>



//--------------------------------------------
Object::Object(
    const float& radius,
    sf::Color color
)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
}


//--------------------------------------------
auto Object::setPosition(Vec2 position) -> void
{

}


//--------------------------------------------
auto Object::setVelocity(Vec2 velocity) -> void
{

}


//--------------------------------------------
auto Object::setAcceleration(Vec2 acceleration) -> void
{

}

//--------------------------------------------
auto Object::getPosition() -> Vec2
{

}


//--------------------------------------------
auto Object::getVelocity() -> Vec2
{

}


//--------------------------------------------
auto Object::getAcceleration() -> Vec2
{

}
