/*
 * Test.h
 *
 *  Created on: Mar 13, 2016
 *      Author: abd
 */

#ifndef SRC_TEST_H_
#define SRC_TEST_H_

namespace SEFT {

class Test {
public:
    Test(const char * test_case_name, const char * test_name);

    const char * get_test_case_name();

    const char * get_test_name();

    void set_next_test(Test* _test);

    Test * get_next_test();

    virtual void setup();
    virtual void run();
    virtual void teardown();

private:
    const char * test_case_name;
    const char * test_name;
    Test* next_test;
};

} /* namespace SEFT */

#endif /* SRC_TEST_H_ */
