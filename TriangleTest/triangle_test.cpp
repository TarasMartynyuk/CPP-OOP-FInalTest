//
// Created by Taras Martynyuk on 4/18/2018.
//
#include "Triangle.h"
#include <IndependentSegment.h>
#include <cassert>
#include <MainTest/test_utils.h>
#include "triangle_test.h"

Triangle setupTriangle();

void run_all_triangle_tests()
{
    start_of_median_eq_opposite_apex();
}

void start_of_median_eq_opposite_apex()
{
    Triangle triangle = setupTriangle();

//    Segment median = triangle.medianAB();
//
//    assert(median.start() == triangle.apexC());
//    logPassed(__FUNCTION__);
}

void median_changes_on_apex_change()
{
    Triangle triangle = setupTriangle();

//    Segment median = triangle.medianBC();



}

Triangle setupTriangle()
{
    return Triangle(0, 0, 5, 5, 0, 5);
}
