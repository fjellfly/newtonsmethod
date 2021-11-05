#ifndef SOLVE_H
#define SOLVE_H

#include <cppunit/extensions/HelperMacros.h>

class Solve : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(Solve);

    CPPUNIT_TEST(testSolve);

    CPPUNIT_TEST_SUITE_END();

public:
    Solve();
    virtual ~Solve();
    void setUp();
    void tearDown();

private:
    void testSolve();

};

#endif /* SOLVE_H */

