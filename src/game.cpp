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

            if (objects[i].isInCollision(objects[j]))
            {
                auto overlap = objects[i].overlaps(objects[j]); 
                if (overlap > 0)
                {
                    // Handle overlapping
                    auto shifts = handleOverlapping(objects[i], objects[j], overlap);
                    objects[i].setPosition(std::get<0>(shifts)); 
                    objects[j].setPosition(std::get<1>(shifts)); 
                }
                // Handle collision
                auto velocities = handleCollision(objects[i], objects[j]);
                objects[i].setVelocity(std::get<0>(velocities));
                objects[j].setVelocity(std::get<1>(velocities));
            }
            else
            {
                toVecPos = objects[j].getPosition();
                toVecMass = objects[j].getMass();

                distance = computeDistanceBetweenVectors(fromVecPos, toVecPos);
                normalized_dir_vector = getNormDirectionVec2FromTo(toVecPos, fromVecPos);

                acceleration += physics::gravitationalAcceleration(
                    toVecMass, distance, normalized_dir_vector
                );
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
auto Game::handleCollision(Object& a, Object& b) -> std::tuple<Vec2, Vec2>
{
    auto aPos = a.getPosition();
    auto bPos = b.getPosition();
    auto aVel = a.getVelocity();
    auto bVel = b.getVelocity();

    auto vel_diff = aVel - bVel;
    auto dist_diff = aPos - bPos;

    if (vel_diff(0) * dist_diff(0) + vel_diff(1) * dist_diff(1) <= 0) 
    {
        auto x_like_axis = bPos - aPos;
        auto x_axis = composeVec2(1, 0);
        auto rotation_mat = computeRotationMatrix(x_like_axis, x_axis);

        // Rotate to align x_like_axis to x_axis
        aVel = rotation_mat * aVel;
        bVel = rotation_mat * bVel;

        float va = aVel(0);
        float vb = bVel(0);

        float ub = physics::computeVelocityAfterCollision(va, vb, a.getMass(), b.getMass());
        float ua = physics::computeVelocityAfterCollision(vb, va, b.getMass(), a.getMass());

        aVel(0) = ua;
        bVel(0) = ub;

        aVel = rotation_mat.inverse() * aVel;
        bVel = rotation_mat.inverse() * bVel;
    }
    
    return std::make_tuple(aVel, bVel);
} 


//--------------------------------------------
auto Game::handleOverlapping(Object& a, Object& b, float overlap) -> std::tuple<Vec2, Vec2>
{
    auto aPos = a.getPosition();
    auto bPos = b.getPosition();

    Vec2 shift_vector = (bPos - aPos).normalized() * overlap;
    aPos -= shift_vector;
    bPos += shift_vector;

    return std::make_tuple(aPos, bPos);
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