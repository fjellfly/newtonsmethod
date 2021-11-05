#ifndef GETJACOBIAN_H
#define GETJACOBIAN_H

#include <cppunit/extensions/HelperMacros.h>

class GetJacobian : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(GetJacobian);

    CPPUNIT_TEST(testGetJacobian);

    CPPUNIT_TEST_SUITE_END();

public:
    GetJacobian();
    virtual ~GetJacobian();
    void setUp();
    void tearDown();

private:
    void testGetJacobian();
};

#endif /* GETJACOBIAN_H */

