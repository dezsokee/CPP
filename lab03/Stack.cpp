#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int inCapacity) {
    inCapacity = inCapacity;
    cout<<"Stack constructor is called!"<<endl;
}

Stack::~Stack() {
    while (data.size() != 0) {
        pop();
    }
    cout<<"Stack destructor is called!"<<endl;
}

void Stack::push(double e) {
    data.insertFirst(e);
}

bool Stack::isEmpty() const {
    return data.empty();
}

void Stack::pop() {
    if(isEmpty()) {
        cout<<"The stack is empty"<<endl;
        return;
    }
    data.removeFirst();
}
