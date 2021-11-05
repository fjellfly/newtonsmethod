/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   FindRoot.h
 * Author: bernhard
 *
 * Created on 5 Nov 2021, 22:55:58
 */

#ifndef FINDROOT_H
#define FINDROOT_H

#include <cppunit/extensions/HelperMacros.h>

class FindRoot : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(FindRoot);

    CPPUNIT_TEST(testFindRoot);

    CPPUNIT_TEST_SUITE_END();

public:
    FindRoot();
    virtual ~FindRoot();
    void setUp();
    void tearDown();

private:
    void testFindRoot();

};

#endif /* FINDROOT_H */

