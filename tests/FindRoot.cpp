#include <math.h>

#include "FindRoot.h"
#include "../root.h"


CPPUNIT_TEST_SUITE_REGISTRATION(FindRoot);

FindRoot::FindRoot() {
}

FindRoot::~FindRoot() {
}

void FindRoot::setUp() {
}

void FindRoot::tearDown() {
}

void FindRoot::testFindRoot() {
    std::function<std::vector<double> (std::vector<double>)> F = [](std::vector<double> x) {
        std::vector<double> vec(x.size());
        vec.at(0) = x.at(0) / x.at(1) + x.at(2) / x.at(0);
        vec.at(1) = 0.5 * pow(x.at(1), 3) - 250 * x.at(1) * x.at(2) - 75000 * pow(x.at(2), 2);
        vec.at(2) = exp(-x.at(2)) + x.at(2) * exp(1);

        return vec;
    };

    std::vector<double> initialGuess({10, 100, 0});
    const double h = pow(10, -6);
    double epsilon = pow(10, -6);
    int maxIterations = 500;
     
    std::vector<double> result = findRoot(initialGuess, F, maxIterations, epsilon, h);
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL(sqrt(50), result.at(0), pow(10, -6));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(50, result.at(1), pow(10, -6));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-1, result.at(2), pow(10, -6));
}

