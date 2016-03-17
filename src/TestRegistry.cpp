/*
 * TestRegistry.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: abd
 */

#include "TestRegistry.h"
#include <stdio.h>
namespace SEFT {

void TestRegistry::add_test(Test* _test) {
    instance().add(_test);
}

void TestRegistry::add(Test* _test) {
    if (head_test==0) {
        head_test = _test;
    } else {
        last_test->set_next_test(_test);
    }

    last_test = _test;
    _test->set_next_test(0);
}

TestRegistry::TestRegistry() :
        head_test(0), last_test(0) {
}

Test* TestRegistry::get_first_test() {
    return instance().head_test;
}

TestRegistry& TestRegistry::instance() {
    static TestRegistry test_reg;
    return test_reg;
}

} /* namespace SEFT */
