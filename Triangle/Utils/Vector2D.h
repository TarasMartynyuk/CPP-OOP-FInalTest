#ifndef LAB4_VECTOR_H
#define LAB4_VECTOR_H
#include <iosfwd>
#include <ostream>
#include <Triangle/Triangle.h>
#include "TriangleSegment.h"
#include "Point.h"

//*******************************************
//    represents vector in 2d space
//    Developed by Taras Martynyuk
//    on 2/19/2018
//    Version .5
//*******************************************
class Vector2D
{
public:
    Vector2D(double x, double y);
    explicit Vector2D(const Triangle::Segment&);
    Vector2D(const Point&, const Point&);

    const double& x() const;
    const double& y() const;
    double& x();
    double& y();

    // should these methods create a copy instead?
    void normalize();
    double magnitude();

private:
    double x_;
    double y_;
};

std::ostream& operator<<(std::ostream &, const Vector2D &);
const Point operator+(const Point&, const Vector2D&);
const Vector2D operator*(const Vector2D&, double);

Vector2D opposite(const Vector2D&);

#endif //LAB4_VECTOR_H
