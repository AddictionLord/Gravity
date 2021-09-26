#include <gravity/game.hpp>



//--------------------------------------------
auto Game::addObject(
    const float& radius,
    const float& mass,
    const sf::Color& color,
    const Vec2& position,
    const Vec2& velocity,
    const Vec2& acceleration,
    const bool& isStatic) -> void
{
    auto new_object = std::make_shared<Object>(radius, mass, color);

    new_object->setPosition(position);
    new_object->setVelocity(velocity);
    new_object->setAcceleration(acceleration);

    if (isStatic) {new_object->makeStatic();}

    objects.push_back(new_object);
}


//--------------------------------------------
auto Game::computePhysics() -> void
{
    Vec2 normalized_dir_vector, fromVec, toVec, position, velocity, acceleration;
    float distance;
    
    for (size_t i = 0; i < objects.size(); i++)
    {
        acceleration = composeVec2(0, 0);
        fromVec = objects[i]->getPosition();

        for (size_t j = 0; j < objects.size(); j++)
        {
            if (i == j){continue;}

            toVec = objects[j]->getPosition();

            distance = computeDistanceBetweenVectors(fromVec, toVec);
            distance < 1 ? distance = 1 : distance;
            normalized_dir_vector = getNormDirectionVec2FromTo(toVec, fromVec);

            acceleration -= (GRAVITY * objects[j]->getMass()) / (std::pow(distance, 2))
                * normalized_dir_vector;
        }

        if (!objects[i]->getStatic())
        {
            velocity = objects[i]->getVelocity() + acceleration;
            objects[i]->setVelocity(velocity);
            position = objects[i]->getPosition() + velocity;
            objects[i]->setPosition(position);
        }
    }
}


//--------------------------------------------
auto Game::drawObjects(sf::RenderWindow& window) -> void
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        window.draw(objects[i]->getShape());
    }
}