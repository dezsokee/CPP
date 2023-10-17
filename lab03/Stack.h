#ifndef LAB3_STACK_H
#define LAB3_STACK_H

class Stack{
public:
    Stack(int inCapacity);
    ~Stack();
    void push(double inDouble);
    double top() const;
    void pop();
    bool isFull() const;
    bool isEmpty()const;
private:
    int mCapacity;
    int * mElements;
    int mTop;
};

#endif //LAB3_STACK_H
