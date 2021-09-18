#include <Eigen/Dense>


using Vec2 = Eigen::Vector2f;


Vec2 createVec2(float&& x, float&& y)
{
    Vec2 v;
    v << x, y

    return v;
}