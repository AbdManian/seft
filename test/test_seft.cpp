#include <stdio.h>
#include "SEFT.h"
#include "TestRegistry.h"
using namespace SEFT;

TEST(Kalam,Polo)
{
    printf("hello kp\n");
}

TEST(Antar,Sagi)
{
    printf("hello kp\n");
}

TEST(Shalgham,Rashti)
{
    printf("hello kp\n");
}

TEST(Shalgham,Dashti)
{
    printf("hello kp\n");
}

int main()
{

    Test* ts = TestRegistry::get_first_test();
    int i=0;
    while (ts) {
        i++;
        printf("Test %d %s.%s\n",i,ts->get_test_case_name(),ts->get_test_name());
        ts = ts->get_next_test();
    }
    printf("Done!\n");
    return 0;
}
