//*******************************************
//    Lab task 4
//    Developed by Taras Martynyuk
//    on 2/15/2018
//    Version .5
//class Point;
//*******************************************
#ifndef LAB4_TRIANGLE_H
#define LAB4_TRIANGLE_H
#include <iostream>
#include <IndependentSegment.h>
#include "Point.h"

class Triangle
{
public:
    class Side;
    //region ctors

    explicit Triangle(const double x1=0, const double y1=0,
             const double x2=1, const double y2=0,
             const double x3=0, const double y3=1);

    Triangle(const Point& a, const Point& b, const Point& c);
    Triangle (const Triangle&);
    ~Triangle();

    //endregion

    typedef const Side& (Triangle::* SideGetter)() const;

    double perimeter() const;
    double area() const;

    //region accessors

    const Point& apexA() const;
    const Point& apexB() const;
    const Point& apexC() const;
    Point& apexA();
    Point& apexB();
    Point& apexC();

    const Side& sideAB() const;
    const Side& sideBC() const;
    const Side& sideAC() const;

    const ::Segment& medianAB();
    const ::Segment& medianBC();
    const ::Segment& medianAC();

    //endregion
// for the length of the sides, just use Triangle.side{sideVertex}.length()

private:
    using Apex = const Point Triangle::* const;
    using HeightEnd = Point* Triangle::* const;
//    typedef  const Point Triangle::* const Apex;
//    typedef Point* Triangle::* const HeightEnd;

    Point a_, b_, c_;
    mutable Side *ab_, *bc_, *ac_;
    mutable ::Segment *median_ab_, *median_bc_, *median_ac_;

    // not implemented - our triangle is readonly
    Triangle& operator=(const Triangle&);

    // creates new median segment, whose start is apex opposie the side,
    // and end is the center of the side
//    const ::Segment& median(SideGetter);
    ::Segment* createMedian(SideGetter);
    SideGetter getSideOppositeApex(Apex) const;
};

std::ostream& operator<<(std::ostream &, const Triangle &);

//region Segment

class Triangle::Side
{
public:
    Side(const Point & start, const Point & end);
    ~Side();

    const Point& start() const;
    const Point& end() const;

    double length () const;
    ::Segment toIndependentSegment();

private:
    // the references are readonly!
    // so we can't modify apexes from the segment:
    // the binding apex -> segment is one-way!
    const Point& _start;
    const Point& _end;
    // No assignment -
    Side& operator=(const Side&);
};
std::ostream& operator<<(std::ostream &, const Triangle::Side &);
//endregion
#endif //LAB4_TRIANGLE_H

