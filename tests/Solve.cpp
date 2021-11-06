#include <math.h>
#include <iostream>
#include <iostream>

#include "Solve.h"
#include "../solve.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Solve);

Solve::Solve() {
}

Solve::~Solve() {
}

void Solve::setUp() {
}

void Solve::tearDown() {
}

void Solve::testSolve3D() {
    std::vector<std::vector<double>> matrix({
        {5, 2, 3}, {0, 4, -1}, {0, 0, 7}
    });
    std::vector<double> targetValue({15, 34, -14});
    
    std::vector<double> result = solve(matrix, targetValue);
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, result.at(0), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(8, result.at(1), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-2, result.at(2), std::pow(10, -8));    
}

void Solve::testSolve4D() {
    std::vector<std::vector<double>> matrix({
        {2, -2, 1, 2}, {0, 1, 0, -2}, {0, 0, 1, -1}, {0, 0, 0, 1}
    });
    std::vector<double> targetValue({5, 1, 2, 3});

    std::vector<double> result = solve(matrix, targetValue);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(4, result.at(0), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(7, result.at(1), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5, result.at(2), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(3, result.at(3), std::pow(10, -8));
}

void Solve::testSolveExpectUpperTriangleMatrix() {
    std::vector<std::vector<double>> matrix({
        {0, 0, 1}, {0, 1, 0}, {1, 0, 0}
    });
    std::vector<double> targetValue({5, 1, 2});

    CPPUNIT_ASSERT_THROW(solve(matrix, targetValue), std::invalid_argument);
}