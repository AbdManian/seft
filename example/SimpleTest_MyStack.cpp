/*
 * SimpleTest_MyStack.cpp
 *
 *  Created on: Mar 22, 2016
 *      Author: abd
 *
 * Simple test for checking MyStack class using SEFT
 * framework
 */

#include "SEFT.h"
#include "MyStack.h"

TEST(MyStackTest, Basic) {

    MyStack<int> dut;
    dut.clear();

    ASSERT(dut.size()==0);
    dut.push(0xDAAF);
    ASSERT(dut.size()==1);
    ASSERT(dut.is_empty()==false);
    ASSERT(dut.pull()==0xDAAF);
    ASSERT(dut.is_empty()==true);
}

TEST(MyStackTest, CheckFull) {

    MyStack<int> dut;
    dut.clear();


    int magic = 0xABAD;
    int i=0;

    while(dut.is_full()==false) {
        dut.push(i+magic);
        i++;
        ASSERT(dut.size()==i);
    }

    ASSERT(dut.size()==dut.max_size());
}
