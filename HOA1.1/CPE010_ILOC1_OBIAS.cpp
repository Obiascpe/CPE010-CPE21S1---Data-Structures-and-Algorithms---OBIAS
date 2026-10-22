//Create a C++ program to swap the two numbers in different variables.
#include <iostream>

int main(){

    int fnum,lnum,temp;

    std::cout << "Enter first number: ";
    std::cin >> fnum;

    std::cout << "Enter second number: ";
    std::cin >> lnum;

    temp = fnum;
    fnum = lnum;
    lnum = temp;

    std::cout << "\nAfter swapping the first number and second number, the result is: \n";
    std::cout << "First number = " << fnum << "\nSecond number = " << lnum << std::endl;

    return 0;
}