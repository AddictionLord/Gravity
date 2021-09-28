#include <gravity/common.hpp>



namespace physics
{

    inline auto gravitationalAcceleration(
        float& attractorMass,
        float& distance,
        Vec2& normalized_dir_vector) -> Vec2
    {
        return - (GRAVITY * attractorMass) / (std::pow(distance, 2)) * normalized_dir_vector;
    }


//--------------------------------------------
    // inline auto isInCollision()
    // {

    // }

}