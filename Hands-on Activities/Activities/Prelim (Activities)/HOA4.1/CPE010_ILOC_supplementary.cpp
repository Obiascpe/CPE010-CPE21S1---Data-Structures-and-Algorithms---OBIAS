#include <iostream>

// Stack using Array
const int maxcap = 100;
char stack[maxcap];
int top = -1;
std::string exp;

// functions
void push(char newdata);
char pop();
bool isEmpty();
bool isFull();
bool isBalanced();

int main() {

    char c;

    while (c != 'n') {

        std::cout << "Enter the Expression: ";
        std::cin >> exp;

        if (isBalanced()) {
            std::cout << "Expression is VALID." << std::endl;
        }
        else {
            std::cout << "Expression is INVALID." << std::endl;
        }

        std::cout << "Continue? (y/n): ";
        std::cin >> c;
        std::cout << std::endl;
    }

    return 0;
}

bool isBalanced() {
    char temp;
    bool valid = true;

    // reset the stack
    top = -1;

    for (int i = 0; i < exp.length(); i++) {

        // check if it is opening bracket
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(exp[i]);
        }

        // check if it is closing bracket
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {

            // check if stack is empty
            if (isEmpty()) {
                valid = false;
                break;
            }

            // get the top bracket
            temp = pop();

            // compare opening and closing brackets
            if (exp[i] == ')' && temp != '(') {
                valid = false;
                break;
            }

            if (exp[i] == ']' && temp != '[') {
                valid = false;
                break;
            }

            if (exp[i] == '}' && temp != '{') {
                valid = false;
                break;
            }
        }
    }

    // check if there are still brackets left
    if (!isEmpty()) {
        valid = false;
    }

    return valid;
}

void push(char newdata) {
    // check if stack is full
    if (isFull()) {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    // increment the top of stack,then add newdata
    stack[++top] = newdata;
}

char pop() {
    // check if stack is empty
    if (isEmpty()) {
        return ' ';
    }

    // get the top value then decrement top
    char temp = stack[top];
    top--;

    return temp;
}

bool isEmpty() {
    // check if stack is empty
    if (top == -1)
        return true;

    return false;
}

bool isFull() {
    // check if stack is full
    if (top == maxcap - 1)
        return true;

    return false;
}