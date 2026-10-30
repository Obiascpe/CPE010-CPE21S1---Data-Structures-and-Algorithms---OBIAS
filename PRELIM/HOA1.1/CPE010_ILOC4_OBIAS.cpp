#include <iostream>
#include <cmath>

class Triangle {
private:
    double side1, side2, side3;
    double angle1, angle2, angle3;

public:
    Triangle(double s1, double s2, double s3,
             double a1, double a2, double a3);

    bool isValidTriangle();
    double findArea();
    double findPerimeter();
    void displayTriangleType();
};

// Constructor
Triangle::Triangle(double s1, double s2, double s3,
                   double a1, double a2, double a3) {
    side1 = s1;
    side2 = s2;
    side3 = s3;

    angle1 = a1;
    angle2 = a2;
    angle3 = a3;
}

// Check if triangle is valid
bool Triangle::isValidTriangle() {
    if ((angle1 + angle2 + angle3) == 180) {
        return true;
    }
    return false;
}

// Compute perimeter
double Triangle::findPerimeter() {
    return side1 + side2 + side3;
}

// Compute area using Heron's Formula
double Triangle::findArea() {
    double semiPerimeter = findPerimeter() / 2.0;

    return std::sqrt(semiPerimeter *
                     (semiPerimeter - side1) *
                     (semiPerimeter - side2) *
                     (semiPerimeter - side3));
}

// Determine triangle type
void Triangle::displayTriangleType() {

    if (angle1 < 90 && angle2 < 90 && angle3 < 90) {
        std::cout << "Triangle Type: Acute Triangle" << std::endl;
    }
    else if (angle1 > 90 || angle2 > 90 || angle3 > 90) {
        std::cout << "Triangle Type: Obtuse Triangle" << std::endl;
    }
    else {
        std::cout << "Triangle Type: Others" << std::endl;
    }
}

int main() {

    double s1, s2, s3;
    double a1, a2, a3;
    int choice;

    std::cout << "Enter Side 1: ";
    std::cin >> s1;

    std::cout << "Enter Side 2: ";
    std::cin >> s2;

    std::cout << "Enter Side 3: ";
    std::cin >> s3;

    std::cout << "Enter Angle 1: ";
    std::cin >> a1;

    std::cout << "Enter Angle 2: ";
    std::cin >> a2;

    std::cout << "Enter Angle 3: ";
    std::cin >> a3;

    Triangle t(s1, s2, s3, a1, a2, a3);

    if (!t.isValidTriangle()) {
        std::cout << "\nThe given values do not form a valid triangle." << std::endl;
        return 0;
    }

    std::cout << "\n===== MENU =====" << std::endl;
    std::cout << "1. Compute Area" << std::endl;
    std::cout << "2. Compute Perimeter" << std::endl;
    std::cout << "3. Determine Triangle Type" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Area = " << t.findArea() << std::endl;
            break;

        case 2:
            std::cout << "Perimeter = " << t.findPerimeter() << std::endl;
            break;

        case 3:
            t.displayTriangleType();
            break;

        default:
            std::cout << "Invalid menu choice." << std::endl;
    }

    return 0;
}