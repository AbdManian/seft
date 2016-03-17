/*
 * TestRegistry.h
 *
 *  Created on: Mar 17, 2016
 *      Author: abd
 */

#ifndef SRC_TESTREGISTRY_H_
#define SRC_TESTREGISTRY_H_

#include "Test.h"

namespace SEFT {

class TestRegistry {
public:
    TestRegistry();

    static void add_test(Test* _test);

    static Test* get_first_test();

    void add(Test* _test);

private:
    static TestRegistry& instance();
    Test* head_test;
    Test* last_test;
};

} /* namespace SEFT */

#endif /* SRC_TESTREGISTRY_H_ */
