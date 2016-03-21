# seft
Simple Embedded Friendly Test-framework for C++

## Introduction
This is a lite unit-testing framework based 
on [CppUnitLite](http://c2.com/cgi/wiki?CppUnitLite) and [EasyUnit](http://easyunit.sourceforge.net/). No use
of STL, RTTI or dynamic memory make it suitable for embedded systems.

* Portable (only depends on `string.h`) and lightweight test framework
* Supports test grouping in form of test-case/test
* Supports test-fixture

## How to Use
For porting SEFT to any platform, implementation of TestRunner class is required. 

```c++
#include "TestRunner.h"

class MyTestRunner : public TestRunner {
public:
    /* Get name of target test(s) to be executed */ 
    const char * platform_get_test_command() { }

    /* Report failed test */
    void platform_report_failed_test(const char * file_name,
            int line_number, const char * test_case_name,
            const char * test_name) { }

    /* Test header is called before running every test */
    void platform_report_test_header(const char * test_case_name,
            const char * test_name) { }
    
    /* Report test results when all test are finished */
    void platform_report_test_results(int _num_ok_tests,
            int _num_nok_tests) { }
};
```
The derived class is used in main function.
```c++
#include "TestRegistry.h"
#include "MyTestRunner.h"

int main()
{
    MyTestRunner mtr;
    TestRegistry::run_test(&mtr);
    
    return 0;
}
```

## Write Tests in SEFT
Simple tests:
```c++
#include "SEFT.h" /* The only required include file */ 

/* All test are registed automaticly */

TEST(TestCaseXX, TestName) {
    /* You can call this test using "TestCaseXX.TestName". */
    /* Content of the test */

    /* Use ASSERT macro for checking properties */
    ASSERT(1==1);
}

Test(TestCaseXX, AnotherTest) {
    /* This is another test under TestCaseXX */
}

Test(OtherTestCase, NewTest) {
    /* ..... */
}
```

Writing test-fixtures is simple to.
```c++
#include "SEFT.h" 

DECLARE_TESTF(TestCaseFixtureXX)

/* Define local variables here.
 */
int SomeVar;

/* Optionally define Setup or Teardown functions */
SETUP()
{
    SomeVar = 10;
}

TEARDOWN()
{
    SomeVar = 0;
}
END_DECLARE_TESTF() /* Always Finish test-fixtures with END_DECLARE_TESTF */

/* 1. Tests under test-fixture should use TESTF() instead of TEST()
 * 2. Test-case name should be same as test-case used in fixture
 */
TESTF(TestCaseFixtureXX, NameOfTest)
{
    ASSERT(SomeVar==19);
}

TESTF(TestCaseFixtureXX, AnotherTest) {

    /* Body of the test .... */
}
```

## How select a test for execution
Target test is determined using a string called _test_command_. 
Supported formats for _test_command_ are:
* *all* Run all registred tests
* *TestCaseXX.MyTest* Run a single test. MyTest under TestCaseXX
* *TestCaseXX* Run all tests under TestCaseXX

_Test_command_ can be provided by `const char * platform_get_test_command` based 
on the platform. Second method is by defining `__EXT_TEST_COMMAND__` macro on
compile time using build system (for example Make or Scons). 
The second method is implemented in the provided Scons file. 

`$ scons run-test=TestCaseXX.MyTest`

This command runs _TestCaseXX.MyTest_ by defining `__EXT_TEST_COMMAND__`. In this mode
`platform_get_test_command` is ignored. 

_seft_ in Persian means Solid!
