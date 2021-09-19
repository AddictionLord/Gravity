#include <gravity/game.hpp>



//--------------------------------------------
auto Game::addObject(
    const float& radius,
    const float& mass,
    const sf::Color& color,
    const Vec2& position,
    const Vec2& velocity,
    const Vec2& acceleration) -> void
{
    auto new_object = std::make_shared<Object>(radius, mass, color);

    new_object->setPosition(position);
    new_object->setVelocity(velocity);
    new_object->setAcceleration(acceleration);

    objects.push_back(new_object);
}


//--------------------------------------------
auto Game::computePhysics() -> void
{
    Vec2 normalized_dir_vector, fromVec, toVec;
    Vec2 position, velocity, acceleration = composeVec2(0, 0);
    float distance;
    
    for (size_t i = 0; i < objects.size(); i++)
    {
        fromVec = objects[i]->getPosition();
        for (size_t j = 0; j < objects.size(); j++)
        {
            toVec = objects[j]->getPosition();

            distance = computeDistanceBetweenVectors(
                fromVec, toVec
            );

            normalized_dir_vector = getNormDirectionVec2FromTo(
                fromVec, toVec
            );

            acceleration -= (GRAVITY * objects[j]->getMass() / distance)
                * normalized_dir_vector;
        }

        velocity = objects[i]->getVelocity() + acceleration;
        objects[i]->setVelocity(velocity);
        position = objects[i]->getPosition() + velocity;
        objects[i]->setPosition(position);
    }
}


//--------------------------------------------
auto Game::drawObjects() -> void
{

}