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

    // Computes ub (velocity of object B in x axis after collision) 
    inline auto computeVelocityAfterCollision(
        const float& va,
        const float& vb,
        const float& ma,
        const float& mb
    ) -> float
    {
        return 0.98 * ((2 * va * ma) / (ma + mb)) + ((vb * (mb - ma)) / (mb + ma));
    }

}