#include <iostream>
#include <stack> //calling stack from the STL

int main () {
    //create an object for the stack
    std::stack<int> newStack;

    //checking if the stack is empty (empty:true)
    std::cout << "Stack empty? " << newStack.empty() << std::endl;

    //push to the stack
    newStack.push(3);
    newStack.push(8);
    newStack.push(15);

    //checking if the stack is empty (empty:false)
    std::cout << "Stack empty? " << newStack.empty() << std::endl;

    //checking the size of the stack (size:3)
    std::cout << "The size of the stack size: " << newStack.size() << std::endl;

    //checking the top of the stack (top:15)
    std::cout << "The top of the element is: " << newStack.top() << std::endl;

    //removing the element from the top of the stack
    std::cout << "Removing elements from the stack: \n" ;
    newStack.pop();
    std::cout << "The top of the element is " << newStack.top() << std::endl; //checking the top
    newStack.pop();
    std::cout << "The top of the element is " << newStack.top() << std::endl; //checking the top
    newStack.pop();

    //checking if the stack is empty (empty:true)
    std::cout << "Stack empty? " << newStack.empty() << std::endl;

    return 0;
}