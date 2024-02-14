#ifndef MYSTACK_HPP
#define MYSTACK_HPP
class MyStack {
public:
    int size;
    int capacity;
    int* data;

    //constructors
    MyStack();

    MyStack(const MyStack& other);

    //destructor
    ~MyStack();

    //methods
    void resize();

    void push(int value);

    int pop();

    int top();

    bool isEmpty();

    int getSize();
};
#endif