/*
 * Test.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: abd
 */

#include "Test.h"
#include "TestRegistry.h"

namespace SEFT {

Test::Test(const char* test_case_name, const char* test_name) :
        test_case_name(test_case_name), test_name(test_name) {
    next_test = 0;
    TestRegistry::add_test(this);
}

void Test::setup() {

}

void Test::run() {

}

void Test::add_test_result(bool result, const char* file_name,
        int line_number) {
    TestRegistry::add_test_result(this, result, file_name, line_number);
}

void Test::teardown() {

}

const char* Test::get_test_case_name() {
    return test_case_name;
}

const char* Test::get_test_name() {
    return test_name;
}

void Test::set_next_test(Test* _test) {
    next_test = _test;
}

Test* Test::get_next_test() {
    return next_test;
}

}

