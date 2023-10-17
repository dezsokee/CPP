#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int inCapacity) {
    mCapacity = inCapacity;
    mElements = new double[mCapacity];
    mTop = -1;
}

Stack::~Stack() {
    delete [] mElements;
}

bool Stack::isFull() const {
    return mTop == mCapacity - 1;
}

void Stack::push(double inDouble) {
    if(isFull()) {
        cout<<"The stack is full"<<endl;
        return;
    }
    ++mTop;
    mElements[mTop] = inDouble;

}

bool Stack::isEmpty() const {
    return mTop == -1;
}

double Stack::top() const {
    if(isEmpty()) {
        cout<<"The stack is empty"<<endl;
        return -1;
    }
    return mElements[mTop];
}

void Stack::pop() {
    if(isEmpty()) {
        cout<<"The stack is empty"<<endl;
        return;
    }
    --mTop;
}
