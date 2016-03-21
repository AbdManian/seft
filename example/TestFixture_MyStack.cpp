/*
 * TestFixture_MyStack.cpp
 *
 *  Created on: Mar 22, 2016
 *      Author: abd
 *
 *  Show usage of the test-fixture in SEFT framework
 *
 */


#include "SEFT.h"
#include "MyStack.h"


DECLARE_TESTF(MyStackFixture)

/* Here define local variables that are available to all
 * tests under this test-fixture.
 */
MyStack<int> dut;


SETUP()
{
    dut.clear();
}

TEARDOWN()
{
    /* Definition of teardown or setup functions are optional */
}

END_DECLARE_TESTF()


/* 1. Tests under test-fixture should use TESTF() instead of TEST()
 * 2. Test-case name should be same as test-case used in fixture
 */
TESTF(MyStackFixture, Basic)
{
    ASSERT(dut.is_empty());
    ASSERT(dut.size()==0);
    dut.push(0x12345);
    dut.push(0x6789A);
    dut.push(0xBCDEF);

    ASSERT(dut.size()==3);
    ASSERT(dut.is_empty()==false);

    ASSERT(dut.pull() == 0xBCDEF);

    dut.pull(); dut.pull();

    ASSERT(dut.is_empty());
}

TESTF(MyStackFixture, Full) {

    int max = dut.max_size();

    for (int i = 0; i < max; ++i) {
        dut.push(0xDEFA + i);
        ASSERT(dut.size()==(i+1));
    }

    ASSERT(dut.is_full());
    ASSERT(dut.pull()==(0xDEFA+max-1));
}

