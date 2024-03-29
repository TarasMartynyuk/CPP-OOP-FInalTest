//
// Created by Taras Martynyuk on 4/17/2018.
//
#include "IndependentSegment.h"
#include "Vector2D.h"
#include "vector_utils.h"
#include <cmath>

//region ctors

Segment::Segment(const Point& start, const Point& end)
    : _start(start), _end(end)
{}

Segment::~Segment(){}
//endregion
//region getters & setters

const Point& Segment::start() const
{
    return _start;
}

const Point& Segment::end() const
{
    return _end;
}
//endregion

double Segment::length() const
{
    return distance(start(), end());
}

std::ostream& operator<<(std::ostream &, const Segment& segment)
{
    std::cout << "\n\t(" << segment.start() << ", " << segment.end() << ");";
}

Point center(const Segment& segment)
{
    Vector2D dir = toVector2D(segment).normalize();

    return segment.start() + (dir * (segment.length() / 2));
}

bool operator==(const Segment& left, const Segment& right)
{
    return left.start() == right.start() &&
       left.end() == right.end();
}

bool operator!=(const Segment& left, const Segment& right)
{
    return ! (left == right);
}
