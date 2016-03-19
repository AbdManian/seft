/*
 * TestRunner.h
 *
 *  Created on: Mar 17, 2016
 *      Author: abd
 */

#ifndef SRC_TESTRUNNER_H_
#define SRC_TESTRUNNER_H_

#include "Test.h"
namespace SEFT {

class TestRunner {
public:
    TestRunner();

    virtual ~TestRunner();

    void start(Test* test);


    void add_test_result(Test* _test, bool result, const char * file_name,
            int line_number);

    virtual const char * platform_get_test_command();

    virtual void platform_report_failed_test(const char * file_name,
            int line_number, const char * test_case_name,
            const char * test_name);

    virtual void platform_report_test_results(int _num_ok_tests,
            int _num_nok_tests);

    virtual void platform_report_test_header(const char * test_case_name,
            const char * test_name);


private:

    bool test_is_executable(Test* test);

    void run_test(Test* test);

    void walk_on_tests(Test* test);

    void parse_test_command();

    const char * test_command;
    bool _run_all_tests;

    int num_ok_test;
    int num_nok_tests;
    bool cur_test_ok;

    /* Index of TestName when test_command is in format of "TestCase.TestName" */
    int _pos_test_name;
};

} /* namespace SEFT */

#endif /* SRC_TESTRUNNER_H_ */
