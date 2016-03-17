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
};

} /* namespace SEFT */

#endif /* SRC_TESTRUNNER_H_ */
