//
// Created by Taras Martynyuk on 4/18/2018.
//
#include "Triangle.h"
#include <IndependentSegment.h>
#include <cassert>
#include <MainTest/test_utils.h>
#include <Triangle/Utils/vector_utils.h>
#include "triangle_test.h"

Triangle setupTriangle();

void run_all_triangle_tests()
{
    start_of_median_eq_opposite_apex();
    median_changes_on_apex_change();
    median_divides_side_evenly();
}

void start_of_median_eq_opposite_apex()
{
    Triangle triangle = setupTriangle();

    assert(triangle.medianAB().start() == triangle.apexC());
    assert(triangle.medianBC().start() == triangle.apexA());
    assert(triangle.medianAC().start() == triangle.apexB());

    logPassed(__FUNCTION__);
}

void median_changes_on_apex_change()
{
    Triangle triangle = setupTriangle();

    Segment old_med_ab = triangle.medianAB().toIndependentSegment();
    Segment old_med_bc = triangle.medianBC().toIndependentSegment();
    Segment old_med_ac = triangle.medianAC().toIndependentSegment();

    triangle.setApexA(Point(-5, -5));

    assert(triangle.medianAB().toIndependentSegment() != old_med_ab);
    assert(triangle.medianBC().toIndependentSegment() != old_med_bc);
    assert(triangle.medianAC().toIndependentSegment() != old_med_ac);

    logPassed(__FUNCTION__);
}

void median_divides_side_evenly()
{
    Triangle triangle = setupTriangle();

    const Triangle::Side& med_ab = triangle.medianAB();
    const Triangle::Side& med_bc = triangle.medianBC();
    const Triangle::Side& med_ac = triangle.medianAC();

    assert(distance(med_ab.end(), triangle.apexA()) ==
    distance(med_ab.end(), triangle.apexB()));

    assert(distance(med_bc.end(), triangle.apexB()) ==
        distance(med_bc.end(), triangle.apexC()));

    assert(distance(med_ac.end(), triangle.apexA()) ==
           distance(med_ac.end(), triangle.apexC()));

    logPassed(__FUNCTION__);
}

Triangle setupTriangle()
{
    return Triangle(0, 0, 5, 5, 5, 0);
}
