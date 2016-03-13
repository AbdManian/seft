# seft
Simple Embedded Friendly Test-framework for C++

## Introduction
This is a lite unit-testing framework based 
on [CppUnitLite](http://c2.com/cgi/wiki?CppUnitLite) and [EasyUnit](http://easyunit.sourceforge.net/). No use
of STL, RTTI or dynamic memory make it suitable for embedded systems.

## Porting
User only needs to implement the error-reporting function based on the 
embedded target. 
Tests to be run, can be selected using build system or optionally by 
providing a function that gets target test from user.



_seft_ in Persian means Solid!
