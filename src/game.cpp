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
    auto& new_object = objects.emplace_back(radius, mass, color);

    new_object.setPosition(position);
    new_object.setVelocity(velocity);
    new_object.setAcceleration(acceleration);

    if (isStatic) {new_object.makeStatic();}
}


//--------------------------------------------
auto Game::computePhysics() -> void
{
    Vec2 normalized_dir_vector, fromVecPos, toVecPos, position, velocity, 
        acceleration;
    float distance, fromVecMass, toVecMass;
    
    for (size_t i = 0; i < objects.size(); i++)
    {
        acceleration = composeVec2(0, 0);
        fromVecPos = objects[i].getPosition();
        fromVecMass = objects[i].getMass(); 

        for (size_t j = 0; j < objects.size(); j++)
        {
            if (i == j) continue;

            toVecPos = objects[j].getPosition();
            toVecMass = objects[j].getMass();

            distance = computeDistanceBetweenVectors(fromVecPos, toVecPos);
            distance < 1 ? distance = 1 : distance;
            normalized_dir_vector = getNormDirectionVec2FromTo(toVecPos, fromVecPos);

            acceleration += physics::gravitationalAcceleration(
                toVecMass, distance, normalized_dir_vector
            );

            if (objects[i].isInCollision(objects[j]))
            {
                // Handle collision
            }
            
        }

        // Static objects don't get velocity and position updated
        if (!objects[i].getStatic())
        {
            velocity = objects[i].getVelocity() + acceleration;
            objects[i].setVelocity(velocity);
            position = objects[i].getPosition() + velocity;
            objects[i].setPosition(position);
        }
    }
}


//--------------------------------------------
auto Game::drawObjects(sf::RenderWindow& window) -> void
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        window.draw(objects[i].getShape());
    }
}


//--------------------------------------------
auto Game::panningMechanics(
    sf::View& view, 
    sf::Vector2f& viewCenter) -> void
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        view.setCenter(viewCenter.x -= 15, viewCenter.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        view.setCenter(viewCenter.x += 15, viewCenter.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        view.setCenter(viewCenter.x, viewCenter.y -= 15);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        view.setCenter(viewCenter.x, viewCenter.y += 15);
    }
}