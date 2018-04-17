//
// Created by TheSmokingGnu on 2/15/2018.
//
#include <cmath>
#include <cassert>
#include "Triangle.h"
#include "Vector2D.h"
//region defs

Vector2D unitPerpendicularFromPointToSegment(const Point& start, const Triangle::Segment& segment);
double cumulativeFarness(const Point& static_point_a, const Point& static_point_b, const Point& moving_point);
//endregion

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

const Triangle::Segment& Triangle::sideA() const
{
    if(bc_ == nullptr)
    {
        bc_ = new Segment(b_, c_);
    }
    return *bc_;
}

const Triangle::Segment& Triangle::sideB() const
{
    if(ac_ == nullptr)
    {
        ac_ = new Segment(a_, c_);
    }
    return *ac_;
}

const Triangle::Segment& Triangle::sideC() const
{
    if(ab_ == nullptr)
    {
        ab_ = new Segment(a_, b_);
    }
    return *ab_;
}
//endregion
//region methods

double Triangle::perimeter() const
{
    return sideA().length() + sideB().length() + sideC().length();
}

double Triangle::area() const
{
    double half_perim = perimeter() / 2;
    return sqrt(half_perim * (half_perim - sideA().length()) *
                        (half_perim - sideB().length()) * (half_perim - sideC().length()));
}


//region height construction

Triangle::SideGetter Triangle::getSideOppositeApex(Apex apex) const
{
    if(apex == &Triangle::a_)
    {
        return &Triangle::sideA;
    }
    else if(apex == &Triangle::b_)
    {
        return &Triangle::sideB;
    }
    else if(apex == &Triangle::c_)
    {
        return &Triangle::sideC;
    }
    else
    {
        throw std::invalid_argument("passed member pointer is not one of the apexes");
    }
}

// the vector can point towards or away from the segment
Vector2D unitPerpendicularFromPointToSegment(const Point& start, const Triangle::Segment& segment)
{
    Vector2D side_vector(segment);
    assert(side_vector.x() != 0 || side_vector.y() != 0);

    //(0,5)
    // we care only about direction, so let's use a random x to solve the equation
    double p_vec_x;
    double p_vec_y;
    // perpendicular_vector * side_vector = 0
    if(side_vector.x() == 0)
    {
        // 0 * pv.x + sv.y * pv.y = 0;
        //sv.y * pv.y = 0  && sv.y != 0 => pv.y = 0
        // arbitrary x
        p_vec_x = 1;
        p_vec_y = 0;
    }
    else
    {
        // sgb.x * pv.x + sgv.y(can be 0) * pv.y = 0;
        p_vec_y = 1;
        p_vec_x = - (side_vector.y() * p_vec_y) / side_vector.x();
    }

    Vector2D perpendicular_vector(p_vec_x, p_vec_y);
    assert(perpendicular_vector.x() * side_vector.x()  +  perpendicular_vector.y() * side_vector.y() == 0);

    perpendicular_vector.normalize();   // it is now a unit vector with needed direction
    return perpendicular_vector;
}

// function which accesses the distance from the 3d point to the first 2
double cumulativeFarness(const Point& static_point_a, const Point& static_point_b, const Point& moving_point)
{
    const double distance_from_a = Vector2D(static_point_a, moving_point).magnitude();
    const double distance_from_b = Vector2D(static_point_b, moving_point).magnitude();
    return distance_from_a + distance_from_b;
}

//endregion
//endregion

//region Segment

Triangle::Segment::Segment(const Point& start, const Point& end)
    : _start(start), _end(end)
{}

Triangle::Segment::Segment(const Triangle::Segment& other)
    : Segment(other.start(), other.end())
{}

Triangle::Segment::~Segment(){}
//endregion

//region getters & setters
const Point& Triangle::Segment::start() const
{
    return _start;
}

const Point& Triangle::Segment::end() const
{
    return _end;
}
//endregion

double Triangle::Segment::length() const
{
    return sqrt( pow(_end.x() - _start.x(), 2) + pow(_end.y() - _start.y(), 2) );
}

std::ostream& operator<<(std::ostream &, const Triangle::Segment& segment)
{
    std::cout << "\n\t(" << segment.start() << ", " << segment.end() << ");";
}
//endregion