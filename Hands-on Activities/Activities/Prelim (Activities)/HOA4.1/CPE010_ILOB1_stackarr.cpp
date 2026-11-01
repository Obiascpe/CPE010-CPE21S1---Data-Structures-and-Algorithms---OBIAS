#include <iostream>

//static array, what do we need?
const size_t maxCap = 100;
int stack[maxCap];
int top = -1, i, newData;
//always -1 is the top of the stack if it is empty

//functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void display();

int main() {
    int choice;
    std::cout << "Enter the number of max elements for the new stack: ";
    std::cin >> i;
    push();

    while(true) {
        std::cout << "\nstack operations:" << std::endl;
        std::cout << "1. PUSH 2. POP 3. TOP 4. ifEMPTY 5. DISPLAY 6. END" << std::endl;
        std::cin >> choice;
        switch(choice) {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout << isEmpty() << std::endl;
            break;
            case 5: display();
            break;
            case 6: std:: cout << "end of the program" << std::endl;
            return 0;
            default: std::cout << "invalid choice." << std::endl;
            break;
        }
    }

    return 0;
}

bool isEmpty() {
    //create a condition to check whether the top element is equal to -1
    if (top == -1) return true;
    return false;
}

bool isFull() {
    //check if we reached the maximum capacity of the array
    if (top >= i-1) return true;
    return false;
}

void push() {
    //check if full -> if yes return an error
    if (isFull()) {
        std::cout << "stack overflow" << std::endl;
        return;
    }

    std::cout << "\nNew Value to add into the stack:" << std::endl;
    std::cin >> newData;

    //increment the top(index by 1) then assign the new data;
    stack[++top] = newData;
}

void Top() {
    //check if the stack is empty
    if (isEmpty()) {
        std::cout << "stack underflow" << std::endl;
    }

    //
    std::cout << "The element on the top of the stack is " << stack[top] << std::endl;
}

void pop() {
    //check if the stack is empty
    if (isEmpty()) {
        std::cout << "stack underflow" << std::endl;
    }

    //display the top value
    std::cout << "popping" << stack[top] << std::endl;
    top--;
}

void display() {
    //printing all the elements on the stack
    std:: cout << "STACK:" << std::endl;
    for (int j = top; j != -1; j--) {
        std::cout << stack[j] << std::endl;
    }
}