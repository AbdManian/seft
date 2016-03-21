/*
 * TestRegistry.h
 *
 *  Created on: Mar 17, 2016
 *      Author: abd
 */

#ifndef SRC_TESTREGISTRY_H_
#define SRC_TESTREGISTRY_H_

#include "Test.h"
#include "TestRunner.h"

namespace SEFT {

class TestRegistry {
public:
    TestRegistry();

    static void add_test(Test* _test);

    static void run_test(TestRunner* runner);

    static void add_test_result(Test* _test, bool result,
            const char * file_name, int line_number);

    void add(Test* _test);

    void run(TestRunner* runner);

    void add_result(Test* _test, bool result, const char * file_name,
            int line_number);
private:
    static TestRegistry& instance();
    Test* head_test;
    Test* last_test;
    TestRunner* test_runner;
};

} /* namespace SEFT */

#endif /* SRC_TESTREGISTRY_H_ */
