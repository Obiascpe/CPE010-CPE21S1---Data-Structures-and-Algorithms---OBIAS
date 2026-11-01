#ifndef HOA5P1_ILOC_PRINTER_H
#define HOA5P1_ILOC_PRINTER_H

#include <iostream>
#include "HOA5p1_ILOC_job.h"

//array circular queue
template <class T>
class queueArr {
private:
    //create a pointer array
    T *q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    //prototypes
    queueArr(size_t capacity);
    bool Empty();
    bool Full();
    size_t Size();
    void Clear();
    T Front();
    T Back();
    void Enqueue(T newData);
    void Dequeue();
    ~queueArr();
};

//constructor
template <class T>
queueArr<T>::queueArr(size_t capacity) {
    //capacity of the array
    q_capacity = capacity;
    //current size of the queue
    q_size = 0;
    //initial front and back index
    q_front = 0;
    q_back = -1;
    //newly allocated array
    q_array = new T[q_capacity];
}

//destructor
template <class T>
queueArr<T>::~queueArr() {
    delete [] q_array;
}

//empty
template <class T>
bool queueArr<T>::Empty() {
    //check if the queue is empty
    return (q_size == 0);
}

//full
template <class T>
bool queueArr<T>::Full() {
    //check if the queue is full
    return (q_size == q_capacity);
}

//size
template <class T>
size_t queueArr<T>::Size() {
    //return the queue size
    return q_size;
}

//clear
template <class T>
void queueArr<T>::Clear() {
    //reset front and back
    q_front = 0;
    q_back = -1;
    q_size = 0;
}

//front
template <class T>
T queueArr<T>::Front() {
    //check if the queue is empty
    if(Empty()) {
        std::cout << "The queue is empty\n";
        return T();
    }
    //return the front item
    return q_array[q_front];
}

//back
template <class T>
T queueArr<T>::Back() {
    //check if the queue is empty
    if(Empty()) {
        std::cout << "The queue is empty\n";
        return T();
    }
    //return the back item
    return q_array[q_back];
}

//enqueue
template <class T>
void queueArr<T>::Enqueue(T newData) {
    //check if the queue is full
    if(Full()) {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    //move the back circularly
    q_back = (q_back + 1) % q_capacity;
    //assign the new value to the back
    q_array[q_back] = newData;
    //increment the queue size
    q_size++;
}

//dequeue
template <class T>
void queueArr<T>::Dequeue() {
    //check if the queue is empty
    if(Empty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    //move the front circularly
    q_front = (q_front + 1) % q_capacity;
    //decrement the queue size
    q_size--;
}

//printer class
class Printer {
private:
    //create a queue for the jobs
    queueArr<Job> jobs;

public:
    //prototypes
    Printer();
    void AddJob(Job newJob);
    void ProcessJobs();
};

//constructor
Printer::Printer() : jobs(10) {
}

//add a new job
void Printer::AddJob(Job newJob) {
    //add the job to the queue
    jobs.Enqueue(newJob);
    std::cout << "Job added: ";
    newJob.Display();
}

//process all jobs
void Printer::ProcessJobs() {
    std::cout << "\nProcessing jobs...\n" << std::endl;
    //check if there are still jobs
    while(!jobs.Empty()) {
        //get the first job
        std::cout << "Printing: ";
        jobs.Front().Display();
        //remove the first job
        jobs.Dequeue();
        std::cout << "Job completed!\n" << std::endl;
    }
}

#endif