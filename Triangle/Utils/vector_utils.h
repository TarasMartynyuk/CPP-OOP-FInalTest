//
// Created by Taras Martynyuk on 4/18/2018.
//
#ifndef FINALTEST_VECTOR_UTILS_H
#define FINALTEST_VECTOR_UTILS_H

#include <Triangle.h>
#include "TriangleSegment.h"
#include "Vector2D.h"

// should i make this a member?...
Vector2D opposite(const Vector2D&);
double distance(const Point&, const Point&);

Vector2D toVector2D(const Triangle::Side&);
Vector2D toVector2D(const ::Segment&);

#endif //FINALTEST_VECTOR_UTILS_H
