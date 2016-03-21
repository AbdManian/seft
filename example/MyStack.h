/*
 * MyStack.h
 *
 *  Created on: Mar 21, 2016
 *      Author: abd
 */

#ifndef EXAMPLE_MYSTACK_H_
#define EXAMPLE_MYSTACK_H_

#define _MAX_STACK_SIZE 16

template<class T>
class MyStack {
public:
    void push(T value);
    T pull();
    void clear();
    int size();
    bool is_empty();
    bool is_full();
    int max_size();
private:
    T _stack[_MAX_STACK_SIZE];
    int cnt;
};


#endif /* EXAMPLE_MYSTACK_H_ */
