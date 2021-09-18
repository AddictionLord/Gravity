#include <gravity/common.hpp>
#include <SFML/Graphics.hpp>



class Object
{
public:
    Object(
        const float& radius,
        sf::Color color
    );
    ~Object(){};

    auto setPosition(Vec2 position) -> void;
    auto setVelocity(Vec2 velocity) -> void;
    auto setAcceleration(Vec2 acceleration) -> void;

    auto getPosition() -> Vec2;
    auto getVelocity() -> Vec2;
    auto getAcceleration() -> Vec2;



private:
    sf::CircleShape shape;
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;

};