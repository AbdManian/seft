/*
 * MyTestRunner.h
 *
 *  Created on: Mar 21, 2016
 *      Author: abd
 */

#ifndef EXAMPLE_MYTESTRUNNER_H_
#define EXAMPLE_MYTESTRUNNER_H_

#include <stdio.h>
#include "TestRunner.h"

class MyTestRunner : public SEFT::TestRunner {
public:

    void platform_report_failed_test(const char * file_name,
            int line_number, const char * test_case_name,
            const char * test_name) {

        printf("ERROR: %s.%s failed in line=%d %s\n",test_case_name,test_name,line_number,file_name);

    }

    void platform_report_test_results(int _num_ok_tests,
            int _num_nok_tests) {
        if (_num_nok_tests) {
            printf("Test failed. Ok tests= %d/%d\n",_num_ok_tests,(_num_ok_tests+_num_nok_tests));
        } else {
            printf("All tests passed. Ok tests = %d\n",_num_ok_tests);
        }
    }

    void platform_report_test_header(const char * test_case_name,
            const char * test_name) {
        printf(" -------------------------------------- \n");
        printf(" Start %s.%s\n",test_case_name, test_name);
    }

    const char * platform_get_test_command() {
        printf("Enter test command>");

        scanf("%50s", test_cmd_buffer);
        return test_cmd_buffer;
    }

private:
    char test_cmd_buffer[50];
};

#endif /* EXAMPLE_MYTESTRUNNER_H_ */
