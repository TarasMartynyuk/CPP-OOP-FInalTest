//
// Created by Taras Martynyuk on 4/18/2018.
//
#ifndef FINALTEST_VECTOR_UTILS_H
#define FINALTEST_VECTOR_UTILS_H

#include <Triangle.h>
#include "TriangleSegment.h"
#include "Vector2D.h"

// should i make this a member?
Vector2D opposite(const Vector2D&);

// the vector can point towards or away from the segment
//Vector2D unitPerpendicularFromPointToSegment(const Point& start, const Triangle::Segment& segment);

// function which accesses the distance from the 3d point to the first 2
double cumulativeFarness(const Point& static_point_a, const Point& static_point_b, const Point& moving_point);

Vector2D toVector2D(const Triangle::Side&);
Vector2D toVector2D(const ::Segment&);

#endif //FINALTEST_VECTOR_UTILS_H
