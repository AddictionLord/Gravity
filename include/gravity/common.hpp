#pragma once
#include <Eigen/Dense>


using Vec2 = Eigen::Vector2f;


inline Vec2 composeVec2(float&& x, float&& y)
{
    Vec2 vector;
    vector << x, y;

    return vector;
}