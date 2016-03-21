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
    void push(T value)  {
        _stack[cnt] = value;
        cnt++;
    }

    T pull() {
        cnt--;
        return _stack[cnt];
    }

    void clear() {
        cnt = 0;
    }

    int size() {
        return cnt;
    }


    bool is_empty(){
        return cnt==0;
    }

    bool is_full() {
        return cnt>=_MAX_STACK_SIZE;
    }


    int max_size() {
        return _MAX_STACK_SIZE;
    }


private:
    T _stack[_MAX_STACK_SIZE];
    int cnt;
};


#endif /* EXAMPLE_MYSTACK_H_ */
