/*
 * SEFT.h
 *
 *  Created on: Mar 13, 2016
 *      Author: Abd
 */

#ifndef SRC_SEFT_H_
#define SRC_SEFT_H_

#include "Test.h"

#define TEST(test_case_name, test_name) \
    class test_case_name##test_name##_test : public SEFT::Test \
    { public: test_case_name##test_name##_test() : \
    Test(#test_case_name, #test_name) {} \
    void run();}  test_case_name##test_name##_instance;  \
    void test_case_name##test_name##_test::run ()

#define ASSERT(condition)\
    { if (condition) {\
        add_test_result(true, __FILE__, __LINE__); \
    } else {\
        add_test_result(false, __FILE__, __LINE__); return;\
    }}

#endif /* SRC_SEFT_H_ */
