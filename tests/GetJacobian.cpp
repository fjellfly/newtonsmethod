#include <math.h>

#include "GetJacobian.h"
#include "../jacobi.h"

CPPUNIT_TEST_SUITE_REGISTRATION(GetJacobian);

GetJacobian::GetJacobian() {
}

GetJacobian::~GetJacobian() {
}

void GetJacobian::setUp() {
}

void GetJacobian::tearDown() {
}

void GetJacobian::testGetJacobian() {
    std::vector<double> initialGuess({10, 100, 0});
    double h = std::pow(10,-6);
    
    std::function<std::vector<double> (std::vector<double>)> F = [](std::vector<double> x) {
        std::vector<double> vec(x.size());
        vec.at(0) = x.at(0) / x.at(1) + x.at(2) / x.at(0);
        vec.at(1) = 0.5 * std::pow(x.at(1), 3) - 250 * x.at(1) * x.at(2) - 75000 * std::pow(x.at(2), 2);
        vec.at(2) = exp(-x.at(2)) + x.at(2) * exp(1);

        return vec;
    };
    
    std::vector<std::vector<double>> x = getJacobian(initialGuess, F, h);
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, x.at(1).at(0), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, x.at(2).at(0), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, x.at(2).at(1), std::pow(10, -8));
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.01, x.at(0).at(0), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-1/(1000+std::pow(10, -5)), x.at(0).at(1), std::pow(10, -8));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.1, x.at(0).at(2), std::pow(10, -8));
}
 

