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

void TestRegistry::run_test(TestRunner* runner) {
    instance().run(runner);
}

void TestRegistry::run(TestRunner* runner) {
    test_runner = runner;
    test_runner->start(head_test);
}

TestRegistry& TestRegistry::instance() {
    static TestRegistry test_reg;
    return test_reg;
}

void TestRegistry::add_test_result(Test* _test, bool result,
        const char* file_name, int line_number) {
    instance().add_result(_test, result, file_name, line_number);
}

void TestRegistry::add_result(Test* _test, bool result,
        const char* file_name, int line_number) {
    test_runner->add_test_result(_test, result, file_name, line_number);
}

} /* namespace SEFT */


