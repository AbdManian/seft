#include <stdio.h>
#include "SEFT.h"
#include "TestRegistry.h"
using namespace SEFT;


TEST(Felez, Tala  ) { printf("(Felez, Tala  ) \n"); }
TEST(Felez, Mes   ) { printf("(Felez, Mes   ) \n"); }
TEST(Felez, Sorb  ) { printf("(Felez, Sorb  ) \n"); }
TEST(Ghaza, Kalam ) { printf("(Ghaza, Kalam ) \n"); }
TEST(Ghaza, Badem ) { printf("(Ghaza, Badem ) \n"); }
TEST(Fohsh, Zool  ) { printf("(Fohsh, Zool  ) \n"); }

class MyTestRunner : TestRunner {
public:
    const char * platform_get_test_command() {
        return "Felez";
    }

};



int main()
{
    TestRunner tr;
    TestRegistry::run_test(&tr);

    printf("Done!\n");
    return 0;
}
