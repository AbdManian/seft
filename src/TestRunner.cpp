/*
 * TestRunner.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: abd
 */

#include "TestRunner.h"
#include <string.h>

#define ALL_TEST_STR "all"

namespace SEFT {

TestRunner::TestRunner() {

}

TestRunner::~TestRunner() {
}

void TestRunner::start(Test* test) {

#ifdef __EXT_TEST_COMMAND__
    test_command = __EXT_TEST_COMMAND__;
#else
    test_command = platform_get_test_command();
#endif

    parse_test_command();

    walk_on_tests(test);
}

const char* TestRunner::platform_get_test_command() {
    return ALL_TEST_STR;
}

bool TestRunner::test_is_executable(Test* test) {
    if (_run_all_tests) {
        return true;
    }

    if (_pos_test_name) {
        /* Test is in format of "TestCase.TestName" */
        if (strncmp(test->get_test_case_name(), test_command,
                _pos_test_name - 1) == 0
                && strcmp(test->get_test_name(), test_command + _pos_test_name)
                        == 0) {
            return true;
        }
    } else {
        /* Test is in format of "TestCase", only check testcase-name */
        if (strcmp(test->get_test_case_name(), test_command) == 0) {
            return true;
        }
    }

    return false;
}

void TestRunner::walk_on_tests(Test* test) {
    Test * ts = test;
    while (ts) {

        if (test_is_executable(ts)) {
            run_test(ts);
        }

        ts = ts->get_next_test();
    }
}

void TestRunner::run_test(Test* test) {
    test->setup();
    test->run();
    test->teardown();
}

void TestRunner::parse_test_command() {
    _run_all_tests = false;

    if (strcmp(test_command, ALL_TEST_STR) == 0) {
        _run_all_tests = true;
        return;
    }

    /* Check if test_command is in format of "TEST_CASE.TEST_NAME" */
    const char * pch;
    pch = strchr(test_command, '.');

    if (pch == NULL) {
        _pos_test_name = 0;
    } else {
        _pos_test_name = (pch - test_command) + 1;
    }
}

} /* namespace SEFT */
