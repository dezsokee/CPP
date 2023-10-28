#ifndef LAB3_STACK_H
#define LAB3_STACK_H
#include "List.h"

class Stack{
public:
    Stack(int inCapacity);
    ~Stack();
    void push(double inDouble);
    void pop();
    bool isEmpty()const;
private:
    List data;
    int inCapacity;
};

#endif //LAB3_STACK_H
