//
// Created by TheSmokingGnu on 2/15/2018.
//
#include <cmath>
#include <cassert>
#include "Triangle.h"
#include "Vector2D.h"
#include "vector_utils.h"

//region ctors

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
    : a_(x1, y1), b_(x2, y2), c_(x3, y3),
      ab_(nullptr), bc_(nullptr), ac_(nullptr)
{}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
    : a_(a), b_(b), c_(c),
      ab_(nullptr), bc_(nullptr), ac_(nullptr)
{}

Triangle::Triangle(const Triangle& other)
    : Triangle(other.apexA(), other.apexB(), other.apexC())
{}

Triangle::~Triangle()
{
    delete ab_;
    delete bc_;
    delete ac_;
}
//endregion
//region accessors

const Point& Triangle::apexA() const
{
    return a_;
}

const Point& Triangle::apexB() const
{
    return b_;
}

const Point& Triangle::apexC() const
{
    return c_;
}

Point& Triangle::apexA()
{
    return a_;
}

Point& Triangle::apexB()
{
    return b_;
}

Point& Triangle::apexC()
{
    return c_;
}

const Triangle::Side& Triangle::sideBC() const
{
    if(bc_ == nullptr)
    {
        bc_ = new Side(b_, c_);
    }
    return *bc_;
}

const Triangle::Side& Triangle::sideAC() const
{
    if(ac_ == nullptr)
    {
        ac_ = new Side(a_, c_);
    }
    return *ac_;
}

const Triangle::Side& Triangle::sideAB() const
{
    if(ab_ == nullptr)
    {
        ab_ = new Side(a_, b_);
    }
    return *ab_;
}

const ::Segment& Triangle::medianAB()
{
    if(median_ab_ == nullptr)
        { median_ab_ = createMedian(&Triangle::sideAB); }

    return *median_ab_;
}

const ::Segment& Triangle::medianBC()
{
    if(median_bc_ == nullptr)
        { median_bc_ = createMedian(&Triangle::sideBC); }

    return *median_bc_;
}

const ::Segment& Triangle::medianAC()
{
    if(median_ac_ == nullptr)
        { median_ac_ = createMedian(&Triangle::sideAC); }

    return *median_ac_;
}
//endregion
//region methods

double Triangle::perimeter() const
{
    SideGetter side = &Triangle::sideBC;
    auto sref =  (this->*side)();
    return sideBC().length() + sideAC().length() + sideAB().length();
}

double Triangle::area() const
{
    double half_perim = perimeter() / 2;
    return sqrt(half_perim * (half_perim - sideBC().length()) *
                        (half_perim - sideAC().length()) * (half_perim - sideAB().length()));
}

//region median

Triangle::SideGetter Triangle::getSideOppositeApex(Apex apex) const
{
    if(apex == &Triangle::a_)
    {
        return &Triangle::sideBC;
    }
    else if(apex == &Triangle::b_)
    {
        return &Triangle::sideAC;
    }
    else if(apex == &Triangle::c_)
    {
        return &Triangle::sideAB;
    }
    else
    {
        throw std::invalid_argument("passed member pointer is not one of the apexes");
    }
}

Segment* Triangle::createMedian(Triangle::SideGetter sideGetter)
{
    const Side& side = (this->*sideGetter)();

}

//endregion
//endregion

//region Side
//region ctors

Triangle::Side::Side(const Point& start, const Point& end)
    : _start(start), _end(end)
{}

Triangle::Side::~Side(){}
//endregion
//region getters & setters

const Point& Triangle::Side::start() const
{
    return _start;
}

const Point& Triangle::Side::end() const
{
    return _end;
}
//endregion

double Triangle::Side::length() const
{
    return sqrt( pow(_end.x() - _start.x(), 2) + pow(_end.y() - _start.y(), 2) );
}

::Segment Triangle::Side::toIndependentSegment()
{
    return ::Segment(start(), end());
}

std::ostream& operator<<(std::ostream &, const Triangle::Side& segment)
{
    std::cout << "\n\t(" << segment.start() << ", " << segment.end() << ");";
}
//endregion