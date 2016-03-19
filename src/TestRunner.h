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

    virtual const char * platform_get_test_command();

private:

    void run_all_test(Test* head_test);

    bool test_is_executable(Test* test);

    void run_test(Test* test);

    void walk_on_tests(Test* test);

    void parse_test_command();

    const char * test_command;
    bool _run_all_tests;

    /* Index of TestName when test_command is in format of "TestCase.TestName" */
    int _pos_test_name;
};

} /* namespace SEFT */

#endif /* SRC_TESTRUNNER_H_ */
