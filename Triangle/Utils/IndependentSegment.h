//
// Created by Taras Martynyuk on 4/17/2018.
//
#ifndef FINALTEST_INDEPENDENTSEGMENT_H
#define FINALTEST_INDEPENDENTSEGMENT_H
#ifndef LAB2_SEGMENT_H
#define LAB2_SEGMENT_H

#include "Point.h"

class Segment
{
public:
    Segment(const Point& start, const Point& end);
    ~Segment();

    // let's make them too readonly for this task
    const Point& start() const;
    const Point& end() const;

    double length () const;

private:
    //  this segment owns it's points, unlike the Triangle's one
    const Point _start;
    const Point _end;
    Segment& operator=(const Segment&);
};

std::ostream& operator<<(std::ostream &, const ::Segment &);

Point center(const ::Segment&);

#endif //LAB2_SEGMENT_H
#endif //FINALTEST_INDEPENDENTSEGMENT_H
