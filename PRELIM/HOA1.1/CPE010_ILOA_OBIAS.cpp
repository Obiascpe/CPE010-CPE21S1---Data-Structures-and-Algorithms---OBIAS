//Header File Declaration Section
#include <iostream>

//Global Declaration Section
int fnum, lnum;
bool x, y;

//Class Declaration and Method Definition Section
//Create a function that will take two numbers and display the sum.
int sum(int fnum, int lnum);

//Create a function that will return whether variable A is greater than variable B.
int compare(int fnum, int lnum);

/*Create a function that will take two Boolean values and display the result
  of all logical operations then  return true if it was a success.*/
bool logicoperation(bool x, bool y);

//Main Function
int main(){

    std::cout << "Enter first number: ";
    std::cin >> fnum;

    std::cout << "Enter last number: ";
    std::cin >> lnum;

    std::cout << "(1=true, 0=false)" << std::endl;
    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    std::cout << "The total number is: " << sum(fnum, lnum) << std::endl;
    if (compare(fnum, lnum) == 1){
        std::cout << fnum << " is greater than " << lnum << std::endl;
    }
    else if (compare(fnum, lnum) == -1){
        std::cout << fnum << " is less than " << lnum << std::endl;
    }
    else{
        std::cout << fnum << " is equal to " << lnum << std::endl;
    }

    logicoperation(x, y);

    return 0;
}

//Method Definition
int sum(int fnum, int lnum){

    int total = fnum + lnum;

    return total;
}

int compare(int fnum, int lnum){

    if (fnum > lnum){
        return 1;
    }
    else if (fnum < lnum){
        return -1;
    }
    else{
        return 0;
    }
}

bool logicoperation(bool x, bool y){

    std::cout << "x AND y: " << (x && y) << std::endl;
    std::cout << "x OR y: " << (x || y) << std::endl;
    std::cout << "NOT x: " << (!x) << std::endl;
    std::cout << "NOT y: " << (!y) << std::endl;

    return 0;
}
