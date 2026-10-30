#include <iostream>
#include "CPE010_HOA4_mainB2.h"

int main() {
    std::cout << "--- PUSHING 'C' 'P' 'E' ONTO THE STACK --- \n";

    //push
    push('C');
    push('P');
    push('E');

    //display the current top
    Top<char>(); //Top should be 'e'

    std::cout << "\n--- DISPLAY ALL --- \n";
    displayAll<char>();

    std::cout << "--- POPPING ALL THE ELEMENTS --- \n";

    //pop
    while (!isEmpty<char>()) {
        std::cout << "Popped: " << pop<char>() << std::endl;
    }

    std::cout << "\n--- TESTING THE UNDERFLOW --- \n";
    pop<char>();

    return 0;
}