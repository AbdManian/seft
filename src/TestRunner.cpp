/*
 * TestRunner.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: abd
 */

#include "TestRunner.h"
#include <string.h>

#define ALL_TEST_STR "all"

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)

namespace SEFT {

TestRunner::TestRunner() {

}

TestRunner::~TestRunner() {
}

void TestRunner::start(Test* test) {

#ifdef __EXT_TEST_COMMAND__
    test_command = STRINGIZE_VALUE_OF(__EXT_TEST_COMMAND__);
#else
    test_command = platform_get_test_command();
#endif

    num_nok_tests = 0;
    num_ok_test = 0;
    cur_test_ok = true;


    parse_test_command();

    walk_on_tests(test);

    platform_report_test_results(num_ok_test,num_nok_tests);
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
    platform_report_test_header(test->get_test_case_name(), test->get_test_name());

    cur_test_ok = true;
    test->setup();
    test->run();
    test->teardown();
    if (cur_test_ok) {
        num_ok_test++;
    } else {
        num_nok_tests++;
    }
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


void TestRunner::add_test_result(Test* _test, bool result,
        const char* file_name, int line_number) {

    if (result==false){
        /* Test failed */
        cur_test_ok = false;
        platform_report_failed_test(file_name, line_number, _test->get_test_case_name(),_test->get_test_name());
    }
}



void TestRunner::platform_report_failed_test(const char* file_name,
        int line_number, const char* test_case_name, const char* test_name) {
}

void TestRunner::platform_report_test_results(int _num_ok_tests,
        int _num_nok_tests) {
}

void TestRunner::platform_report_test_header(const char* test_case_name,
        const char* test_name) {
}
} /* namespace SEFT */

