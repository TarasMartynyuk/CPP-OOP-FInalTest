//
// Created by Taras Martynyuk on 4/18/2018.
//
#include <cassert>
#include <cmath>
#include "vector_utils.h"

Vector2D opposite(const Vector2D& vec)
{
    return {- vec.x(), - vec.y()};
}

double distance(const Point& a, const Point& b)
{
    return sqrt( pow(b.x() - a.x(), 2) + pow(b.y() - a.y(), 2) );
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


