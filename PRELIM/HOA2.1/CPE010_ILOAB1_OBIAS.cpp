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

int main(){
    student stud1("Jave", 19);
    stud1.printdetails();
    student stud2(stud1);
    stud2.printdetails();
    student stud3;
    stud3.printdetails();
    stud3 = stud2;
    stud3.printdetails();

    return 0;
}