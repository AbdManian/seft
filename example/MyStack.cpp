/*
 * MyStack.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: abd
 */

#include "MyStack.h"


template<class T>
inline void MyStack<T>::push(T value) {
    _stack[cnt] = value;
    cnt++;
}


template<class T>
T MyStack<T>::pull() {
    return _stack[cnt--];
}

template<class T>
void MyStack<T>::clear() {
    cnt = 0;
}

template<class T>
int MyStack<T>::size() {
    return cnt;
}

template<class T>
bool MyStack<T>::is_empty() {
    return cnt==0;
}

template<class T>
bool MyStack<T>::is_full() {
    return cnt>=_MAX_STACK_SIZE;
}


template<class T>
int MyStack<T>::max_size() {
    return _MAX_STACK_SIZE;
}
