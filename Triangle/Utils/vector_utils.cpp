//
// Created by Taras Martynyuk on 4/18/2018.
//
#include <cassert>
#include "vector_utils.h"

Vector2D opposite(const Vector2D& vec)
{
    return {- vec.x(), - vec.y()};
}

//Vector2D unitPerpendicularFromPointToSegment(const Point& start, const Triangle::Segment& segment)
//{
//    Vector2D side_vector = toVector2D(segment);
//    assert(side_vector.x() != 0 || side_vector.y() != 0);
//
//    //(0,5)
//    // we care only about direction, so let's use a random x to solve the equation
//    double p_vec_x;
//    double p_vec_y;
//    // perpendicular_vector * side_vector = 0
//    if(side_vector.x() == 0)
//    {
//        // 0 * pv.x + sv.y * pv.y = 0;
//        //sv.y * pv.y = 0  && sv.y != 0 => pv.y = 0
//        // arbitrary x
//        p_vec_x = 1;
//        p_vec_y = 0;
//    }
//    else
//    {
//        // sgb.x * pv.x + sgv.y(can be 0) * pv.y = 0;
//        p_vec_y = 1;
//        p_vec_x = - (side_vector.y() * p_vec_y) / side_vector.x();
//    }
//
//    Vector2D perpendicular_vector(p_vec_x, p_vec_y);
//    assert(perpendicular_vector.x() * side_vector.x()  +  perpendicular_vector.y() * side_vector.y() == 0);
//
//    perpendicular_vector.normalize();   // it is now a unit vector with needed direction
//    return perpendicular_vector;
//}

double cumulativeFarness(const Point& static_point_a, const Point& static_point_b, const Point& moving_point)
{
    const double distance_from_a = Vector2D(static_point_a, moving_point).magnitude();
    const double distance_from_b = Vector2D(static_point_b, moving_point).magnitude();
    return distance_from_a + distance_from_b;
}

Vector2D toVector2D(const ::Segment& segment)
{
    return Vector2D(segment.end().x() - segment.start().x(),
             segment.end().y() - segment.start().y());
}

Vector2D toVector2D(const Triangle::Side& segment)
{
    return Vector2D(segment.end().x() - segment.start().x(),
                    segment.end().y() - segment.start().y());
}
