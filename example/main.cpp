/*
 * main.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: abd
 */

#include "TestRegistry.h"
#include "MyTestRunner.h"

int main()
{
    MyTestRunner mtr;
    SEFT::TestRegistry::run_test(&mtr);

    printf("Done!\n");
    return 0;
}
