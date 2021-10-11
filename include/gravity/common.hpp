#pragma once
#include <Eigen/Dense>
#include <cmath>

const float GRAVITY = 900.81;


using Vec2 = Eigen::Vector2f;
using Mat2 = Eigen::Matrix2f;

inline auto composeVec2(float&& x, float&& y) -> Vec2
{
    Vec2 vector;
    vector << x, y;

    return vector;
}


inline auto getNormDirectionVec2FromTo(Vec2 from, Vec2 to) -> Vec2
{
    return (to - from).normalized();
}


inline auto computeDistanceBetweenVectors(Vec2 a, Vec2 b) -> float
{
    Vec2 substraction = b - a;
    float squared_distance = std::pow(substraction(0), 2) + std::pow(substraction(1), 2);
    float distance = std::sqrt(squared_distance);

    return distance;
}


inline auto computeSquaredDistanceBetweenVectors(Vec2 a, Vec2 b) -> float
{
    Vec2 substraction = b - a;
    float squared_distance = std::pow(substraction(0), 2) + std::pow(substraction(1), 2);

    return squared_distance;
}


// From vector makes matrix used to compute rotation matrix
inline auto computeAuxiliaryMatrix(Vec2 vector) -> Mat2
{
    Mat2 auxiliary_matrix;
    auxiliary_matrix.block<2, 1>(0, 0) = vector;
    auxiliary_matrix(0, 1) = - vector(1);
    auxiliary_matrix(1, 1) = vector(0);

    return auxiliary_matrix;
}


inline auto computeRotationMatrix(Vec2 from, Vec2 to) -> Mat2
{
    Mat2 rotation_matrix, from_matrix, to_matrix;
    from_matrix = computeAuxiliaryMatrix(from);
    to_matrix = computeAuxiliaryMatrix(to);
    rotation_matrix = to_matrix * from_matrix.inverse();

    return rotation_matrix;
}


