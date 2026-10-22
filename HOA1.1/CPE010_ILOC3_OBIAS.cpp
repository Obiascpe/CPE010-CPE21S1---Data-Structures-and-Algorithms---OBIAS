//Create a C++ program that has a function that will calculate the distance between two points.
#include <iostream>
#include <cmath>

double a1, b1, a2, b2;
double distance;

int main(){

    std::cout << "Enter coordinates x1: ";
    std::cin >> a1;

    std::cout << "Enter coordinates y1: ";
    std::cin >> b1;

    std::cout << "Enter coordinates x1: ";
    std::cin >> a2;

    std::cout << "Enter coordinates y2: ";
    std::cin >> b2;

    distance = sqrt(pow(a2 - a1, 2) + pow(b2 - b1, 2));
    std::cout << "Distance is = " << distance << std::endl;

    return 0;
}