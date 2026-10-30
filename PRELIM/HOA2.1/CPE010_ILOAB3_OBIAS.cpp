#include <iostream>
#include <string.h>

class student{
private:
    std::string studentname;
    int studentage;

public:
    //Constructor
    student(std::string newname = "John Doe", int newage = 18){
        studentname = std::move(newname);
        studentage = newage;
        std::cout << "Constructor was called." << std::endl;
    }

    //Deconstructor
    ~student(){
        std::cout << "Destructor was called." << std::endl;
    }

    //Copy Constructor
    student(const student &copystudent){
        std::cout << "Copy constructor was called." << std::endl;
        studentname = copystudent.studentname;
        studentage = copystudent.studentage;
    }

    //Display Attributes
    void printdetails(){
        std::cout << this->studentname << " " << this->studentage << std::endl;
    }

};

int main() {
    const size_t j = 5;
    student studentList[j] = {};
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    for(int i = 0; i < j; i++){ //loop A
        student *ptr = new student(namesList[i], ageList[i]);
        studentList[i] = *ptr;
    }

    for(int i = 0; i < j; i++){ //loop B
        studentList[i].printdetails();
    }

    return 0;
}
