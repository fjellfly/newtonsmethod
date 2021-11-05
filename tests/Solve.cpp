#include <math.h>
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

void Solve::testSolve() {
    std::vector<std::vector<double>> matrix({
        {5, 2, 3}, {0, 4, -1}, {0, 0, 7}
    });
    std::vector<double> targetValue({15, 34, -14});
    
    std::vector<double> result = solve(matrix, targetValue);
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, result.at(0), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(8, result.at(1), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-2, result.at(2), std::pow(10, -8));    
}