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
```C++
#include "TestRegistry.h"
#include "MyTestRunner.h"

int main()
{
    MyTestRunner mtr;
    TestRegistry::run_test(&mtr);
    
    return 0;
}
```


## Porting
User only needs to implement the error-reporting function based on the 
embedded target. 
Tests to be run, can be selected using build system or optionally by 
providing a function that gets target test from user.



_seft_ in Persian means Solid!
