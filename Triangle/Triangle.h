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

//    typedef const Side& (Triangle::* SideGetter)() const;

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

    const Side& medianAB();
    const Side& medianBC();
    const Side& medianAC();

    //endregion
// for the length of the sides, just use Triangle.side{sideVertex}.length()

private:
//    using ApexMPtr = const Point Triangle::* const;
//    using MedianEndMPtr = Point* Triangle::* const;
//    using SideMPTr = Side* Triangle::* const;

    Point a_, b_, c_;
    mutable Point *median_ab_end, *median_bc_end, *median_ac_end;
    mutable Side *ab_, *bc_, *ac_;
    mutable Side *median_ab_, *median_bc_, *median_ac_;

    // not implemented - our triangle is readonly
    Triangle& operator=(const Triangle&);

    // creates new median segment, whose start is apex opposite the side,
    // and end is the center of the side

    // computes the median end for side from current apexes,
    // instantiates the median end for the side with that value
    // and instantiates corresponding median segment from that median end
    const Side& instantiateMedianObject(
        const Side& side, const Point&,
        Point* &, Side* &);
    Point* createMedianEnd(const Side&);

    // updates the existing median end and median objects
    // computing new values from current apexes
    void updatePresentMedianEnds();
    void updateMedianEnd(Point* const p, const Side& side);

    //deletes and sets to null
    void deleteMedians();
    //deletes and sets to null
    void deleteSides();
    void nullifySides();
    void nullifyMedians();
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
    ::Segment toIndependentSegment() const ;

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

