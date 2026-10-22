//Create a C++ program that has a function to convert temperature in Kelvin to Fahrenheit.
#include <iostream>

double converter(double kelvin);
double k, f;

double converter(double kelvin){

    double f = (kelvin - 273.15) * 9 / 5 + 32;

    return f;
}

int main(){

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> k;

    f = converter(k);
    std::cout << "Temperature in Fahrenheit: " << f << std::endl;

    return 0;
}