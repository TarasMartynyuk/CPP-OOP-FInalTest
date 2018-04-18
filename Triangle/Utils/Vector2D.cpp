//
// Created by TheSmokingGnu on 2/18/2018.
//
#include <cmath>
#include "Vector2D.h"
#include "Triangle.h"

//region ctors

Vector2D::Vector2D(double x, double y) : x_(x), y_(y) {}

Vector2D::Vector2D(const Point& start, const Point& end) :
        Vector2D(end.x() - start.x(), end.y() - start.y() ) {}
//endregion
//region accessors

const double& Vector2D::x() const
{
    return x_;
}

const double& Vector2D::y() const
{
    return y_;
}

double& Vector2D::x()
{
    return x_;
}

double& Vector2D::y()
{
    return y_;
}
//endregion
//region methods

double Vector2D::magnitude()
{
    return sqrt(x() * x() + y() * y());
}

void Vector2D::normalize()
{
    double mag = magnitude();
    x() /= mag;
    y() /= mag;
}

//endregion
//region operators

const Point operator+ (const Point& p, const Vector2D& v)
{
    return Point(p.x() + v.x(), p.y() + v.y());
}

const Vector2D operator* (const Vector2D& v, double scalar)
{
    return Vector2D(v.x() * scalar, v.y() * scalar);
}

std::ostream& operator<< (std::ostream& o, const Vector2D& v)
{
    o << "(" << v.x() << ", " << v.y() << ");" << '\n';
}

const Vector2D operator/ (const Vector2D& vec, double sc)
{
    return Vector2D(vec.x() / sc, vec.y() / 2);
}
//endregion


