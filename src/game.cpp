#include <gravity/game.hpp>



//--------------------------------------------
auto Game::addObject(
    const float& radius,
    const sf::Color& color,
    const Vec2& position,
    const Vec2& velocity,
    const Vec2& acceleration) -> void
{
    auto new_object = std::make_shared<Object>(radius, color);

    new_object->setPosition(position);
    new_object->setVelocity(velocity);
    new_object->setAcceleration(acceleration);

    objects.push_back(new_object);
}


//--------------------------------------------
auto Game::computePhysics() -> void
{

}


//--------------------------------------------
auto Game::drawObjects() -> void
{

}