//
// Created by TheSmokingGnu on 2/15/2018.
//
#include <cmath>
#include <cassert>
#include "Triangle.h"
#include "Vector2D.h"
#include "vector_utils.h"

//region ctors

Triangle::Triangle(const double x1, const double y1,
    const double x2, const double y2,
    const double x3, const double y3)
    : Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3))
{}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
    : a_(a), b_(b), c_(c)
{
    nullifySides();
    nullifyMedians();
}

Triangle::Triangle(const Triangle& other)
    : Triangle(other.apexA(), other.apexB(), other.apexC())
{}

Triangle::~Triangle()
{
    deleteMedians();
    deleteSides();
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

const Triangle::Side& Triangle::medianAB()
{
    //
    if(median_ab_end == nullptr)
    {
        median_ab_end = createMedianEnd(sideAB());
        assert(median_ab_ == nullptr);
        median_ab_ = new Side(apexC(), *median_ab_end);
    }

    return *median_ab_;
}

const Triangle::Side& Triangle::medianBC()
{
    if(median_bc_end == nullptr)
    {

    }

    return *median_bc_;
}

//endregion
//region methods

double Triangle::perimeter() const
{
    return sideBC().length() + sideAC().length() + sideAB().length();
}

double Triangle::area() const
{
    double half_perim = perimeter() / 2;
    return sqrt(half_perim * (half_perim - sideBC().length()) *
                        (half_perim - sideAC().length()) * (half_perim - sideAB().length()));
}

//region median

const Triangle::Side& Triangle::instantiateMedianObject(
    const Triangle::Side& side,
    const Point& opposite_apex,
    Point*& median_end,
    Triangle::Side*& median)
{
    if(median_end == nullptr)
    {
        median_end = createMedianEnd(side);
        assert(median == nullptr);
        median = new Side(opposite_apex, *median_end);
    }

    return *median;
}

Point* Triangle::createMedianEnd(const Triangle::Side& side)
{
    return new Point(center(side.toIndependentSegment()));
}

void Triangle::updatePresentMedianEnds()
{

}

void Triangle::updateMedianEnd(Point* const apex, const Side& side)
{
    *apex = center(side.toIndependentSegment());
}

//endregion
//region disposing

void Triangle::deleteMedians()
{
    delete median_ab_;
    delete median_bc_;
    delete median_ac_;
    nullifyMedians();
}

void Triangle::deleteSides()
{
    delete ab_;
    delete bc_;
    delete ac_;
    nullifySides();
}

void Triangle::nullifySides()
{
    ab_ = nullptr;
    bc_ = nullptr;
    ac_ = nullptr;
}

void Triangle::nullifyMedians()
{
    median_ab_ = nullptr;
    median_bc_ = nullptr;
    median_ac_ = nullptr;
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

::Segment Triangle::Side::toIndependentSegment() const
{
    return ::Segment(start(), end());
}

std::ostream& operator<<(std::ostream &, const Triangle::Side& segment)
{
    std::cout << "\n\t(" << segment.start() << ", " << segment.end() << ");";
}
//endregion