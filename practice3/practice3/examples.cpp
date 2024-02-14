#include "examples.hpp"
#include <iostream>
#include "dynarray.hpp"
#include "mystack.hpp"

void DynArrayExample() {
    std::cout << "Working with DynArray:\n";
    DynArray arr(10); // reserve memory for 10 array members
    arr.append(1.0);


    for (size_t i = 0; i < 15; i++) // make sure that the array can dynamically resize
    {
        arr.append(i + 0.0);
    }

    for (size_t j = 0; j < arr.size(); j++)
    {
        std::cout << arr.get(j) << ' '; // should output all 16 elements
    }
    std::cout << std::endl;
}

void MyStackExample() {
    std::cout << "\nWorking with MyStack:\n";

    MyStack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    // Creating a new stack using the copy constructor
    MyStack stackCopy(stack);

    std::cout << "   Original Stack:\n";
    std::cout << "Top element: " << stack.top() << "\n";  // output: Top element: 15
    std::cout << "Popped element: " << stack.pop() << "\n";  // output: Popped element: 15
    std::cout << "Stack size: " << stack.getSize() << "\n";  // output: Stack size: 2
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n";  // output: Is stack empty? No

    std::cout << "\n    Copied Stack:\n";
    stackCopy.push(20);
    std::cout << "Top element: " << stackCopy.top() << "\n";  // output: Top element: 20
    std::cout << "Popped element: " << stackCopy.pop() << "\n";  // output: Popped element: 20
    std::cout << "Stack size: " << stackCopy.getSize() << "\n";  // output: Stack size: 3
    std::cout << "Is stack empty? " << (stackCopy.isEmpty() ? "Yes" : "No") << "\n";  // output: Is stack empty? No
}