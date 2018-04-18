//*******************************************
//    Lab task 4
//    Developed by Taras Martynyuk
//    on 2/15/2018
//    Version .5
//*******************************************
#ifndef LAB2_SEGMENT_H
#define LAB2_SEGMENT_H

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

#endif //LAB2_SEGMENT_H
