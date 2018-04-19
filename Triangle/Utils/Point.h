// 01LAB. Реалізувати і протестувати тип даних Point.
#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>
//*******************************************
//Every point posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a point created or resp. deleted
//    Developed by Taras Martynyuk
//    on 2/15/2018
//    Version .5
//*******************************************

class Point
{
public:
    explicit Point (double x=0, double y=0);
    Point (const Point &);
    ~Point();

    Point& operator=(const Point &);

    double& x();
    double& y();

    const double& x()const;
    const double& y()const;

private:
    double _x;
    double _y;
};

std::ostream& operator<<(std::ostream&, const Point&);

const Point operator+ (const Point & u, const Point & v);

Point& operator+=(Point &, const Point&);

bool operator==(const Point & u, const Point &v);

bool operator!=(const Point & u, const Point &v);

#endif