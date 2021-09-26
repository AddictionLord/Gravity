#pragma once
#include <Eigen/Dense>
#include <cmath>

const float GRAVITY = 900.81;


using Vec2 = Eigen::Vector2f;

inline Vec2 composeVec2(float&& x, float&& y)
{
    Vec2 vector;
    vector << x, y;

    return vector;
}


inline Vec2 getNormDirectionVec2FromTo(Vec2 from, Vec2 to)
{
    return (to - from).normalized();
}


inline float computeDistanceBetweenVectors(Vec2 a, Vec2 b)
{
    Vec2 substraction = b - a;
    float pow = std::pow(substraction(0), 2) + std::pow(substraction(1), 2);
    float distance = std::sqrt(pow);

    return distance;
}