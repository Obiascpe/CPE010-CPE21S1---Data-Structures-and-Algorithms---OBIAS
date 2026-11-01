#ifndef HOA5P1_ILOC_JOB_H
#define HOA5P1_ILOC_JOB_H

#include <iostream>
#include <string>

//Job class
class Job {
    private:
        //job information
        int jobID;
        std::string userName;
        int pages;

    public:
        //prototypes
        Job();
        Job(int id, std::string name, int numPages);
        void Display();
};

//constructor
Job::Job() {
    //initial values
    jobID = 0;
    userName = "";
    pages = 0;
}

//constructor with values
Job::Job(int id, std::string name, int numPages) {
    //assign values
    jobID = id;
    userName = name;
    pages = numPages;
}

//display job information
void Job::Display() {
    std::cout << "Job ID: " << jobID
              << ", User: " << userName
              << ", Pages: " << pages << std::endl;
}

#endif