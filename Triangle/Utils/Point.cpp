//
// Created by TheSmokingGnu on 1/19/2018.
//
#include "Point.h"
using  namespace std;

//region Constructors
int Point::freeID = 0;

Point::Point(double x, double y) : _x{x}, _y{y}, pointID{freeID}
{
    freeID++;
    cout << "Created new Point :" << *this << '\n';
}

Point::Point(const Point &other) : Point(other.x(), other.y()) {}

Point::~Point()
{
    cout << "Deleted Point :" << *this << '\n';
}
//endregion

//region field access

const double& Point::x()const
{
    return this->_x;
}

double& Point::x()
{
    return this->_x;
}

const double& Point::y() const
{
    return this->_y;
}

double& Point::y()
{
    return this->_y;
}

const int Point::getID() const
{
    return this->pointID;
}

int Point::amount()
{
   return freeID;
}

//endregion

//region Operators

Point& Point::operator=(const Point & other)
{
    (*this)._x = other._x;
    (*this)._y = other._y;
    return *this;
}

ostream& operator<<(ostream& stream, const Point& point)
{
    stream << "(" << point.x() << ", " << point.y() << ") ID: " << point.getID();
    return  stream;
}

Point& operator+=(Point & a, const Point& b)
{
    a.x() += b.x();
    a.y() += b.y();
    return a;
}

const Point operator+ (const Point & a, const Point & b)
{
    Point res = a;
    return res += b;
}

bool operator==(const Point & a, const Point &b)
{
    return a.x() == b.x() && a.y() == b.y();
}

bool operator!=(const Point & u, const Point &v)
{
    return !(u == v);
}



//endregion

