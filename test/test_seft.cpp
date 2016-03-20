#include <stdio.h>
#include "SEFT.h"
#include "TestRegistry.h"
using namespace SEFT;


TEST(Felez, Tala  ) { printf("(Felez, Tala  ) \n"); }
TEST(Felez, Mes   ) { printf("(Felez, Mes   ) \n"); }
TEST(Felez, Sorb  ) { printf("(Felez, Sorb  ) \n"); }
TEST(Ghaza, Kalam ) { printf("(Ghaza, Kalam ) \n"); }
TEST(Ghaza, Badem ) { printf("(Ghaza, Badem ) \n"); }
TEST(Fohsh, Zool  ) {
    printf("(Fohsh, Zool  ) \n");
    ASSERT(0);
}


DECLARE_TESTF(Kalam)

    int i;

SETUP()
{
    i = 90;
    printf("Setup Kalam i=%d\n",i);
    i = 80;
}

TEARDOWN()
{
    printf("Teardown kalam i=%d\n",i);
    i=900;

}

END_DECLARE_TESTF()


TESTF(Kalam, FirstTest) { printf("Run Kalam.FirstTest Here i=%d\n",i);}
TESTF(Kalam, Second) { printf("Run Kalam.SecondTest Here i=%d\n",i);}



class MyTestRunner : public TestRunner {
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
        return "all";//"Felez.Mes";
    }

};



int main()
{
    MyTestRunner mtr;
    TestRegistry::run_test(&mtr);

    printf("Done!\n");
    return 0;
}
