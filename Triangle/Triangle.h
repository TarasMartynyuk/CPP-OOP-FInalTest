#ifndef LAB4_TRIANGLE_H
#define LAB4_TRIANGLE_H
#include <iostream>
#include "Point.h"
#include "IndependentSegment.h"
//*******************************************
//    Lab task 4
//    Developed by Taras Martynyuk
//    on 2/15/2018
//    Version .5
//*******************************************
//class Point;

class Triangle
{
public:
    class Segment;
    //region ctors

    explicit Triangle(const double x1=0, const double y1=0,
             const double x2=1, const double y2=0,
             const double x3=0, const double y3=1);

    Triangle(const Point& a, const Point& b, const Point& c);
    Triangle (const Triangle&);
    ~Triangle();

    //endregion

    double perimeter() const;
    double area() const;

    const Point& apexA() const;
    const Point& apexB() const;
    const Point& apexC() const;

    const Triangle::Segment& sideA() const;
    const Triangle::Segment& sideB() const;
    const Triangle::Segment& sideC() const;
// for the length of the sides, just use Triangle.side{sideVertex}.length()

private:
//    using Apex = const Point Triangle::* const;
//    using HeightEnd = Point* Triangle::* const;
    typedef  const Point Triangle::* const Apex;
    typedef Point* Triangle::* const HeightEnd;
    typedef const Triangle::Segment& (Triangle::* SideGetter)() const;

    const Point a_, b_, c_;
    mutable Triangle::Segment *ab_, *bc_, *ac_;
    mutable ::Segment *median_ab, *median_bc, *median_ac;

    // not implemented - our triangle is readonly
    Triangle& operator=(const Triangle&);

    SideGetter getSideOppositeApex(Apex) const;
};

//#include "TriangleSegment.h"
std::ostream& operator<<(std::ostream &, const Triangle &);

//region Segment

class Triangle::Segment
{
public:
    Segment(const Point & start, const Point & end);
    Segment(const Segment &);
    ~Segment();

    const Point& start() const;
    const Point& end() const;

    double length () const;

private:
    // the references are readonly!
    // so we can't modify apexes from the segment
    const Point& _start;
    const Point& _end;
    // No assignment - the binding apex -> segment is one-way!
    Segment& operator=(const Segment&);
};
std::ostream& operator<<(std::ostream &, const Triangle::Segment &);
//endregion


//#include "TriangleSegment.h"
#endif //LAB4_TRIANGLE_H

