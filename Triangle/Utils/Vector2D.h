//*******************************************
//    represents vector in 2d space
//    Developed by Taras Martynyuk
//    on 2/19/2018
//    Version .5
//*******************************************
#ifndef LAB4_VECTOR_H
#define LAB4_VECTOR_H
#include <iosfwd>
#include <ostream>
#include "Point.h"

class Vector2D
{
public:
    Vector2D(double x, double y);
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

std::ostream& operator<< (std::ostream &, const Vector2D &);
const Point operator+ (const Point&, const Vector2D&);
const Vector2D operator* (const Vector2D&, double);
const Vector2D operator/ (const Vector2D&, double);

#endif //LAB4_VECTOR_H
