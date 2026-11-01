#ifndef OBIAS_HOA5P1_ILOB_Arr_H
#define OBIAS_HOA5P1_ILOB_Arr_H

#include <iostream>

//Array-Based Circular Queue
template <typename T>
class queueArr {
    private:
        //create a pointer array:
        T *q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;

    public:
        //prototypes:
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

        //tasks:
        queueArr(const queueArr &other);
        queueArr &operator = (const queueArr &other);
};

//constructor:
template <typename T>
queueArr<T>::queueArr(size_t capacity) {

    //capacity of the array
    q_capacity = capacity;

    //current size of the array
    q_size = 0;

    //initial front and back index
    q_front = 0;
    q_back = -1;

    //newly allocated array
    q_array = new T[q_capacity];
    std::cout << "Constructor class was called\n";
}

//destructor:
template <typename T>
queueArr<T>::~queueArr() {
    delete [] q_array;
};

//empty:
template <typename T>
bool queueArr<T>::Empty() {
    return (q_size == 0);
}

//full:
template <typename T>
bool queueArr<T>::Full() {
    return (q_size == q_capacity);
}

//clear:
template <typename T>
void queueArr<T>::Clear() {
    q_front = 0;
    q_back = -1;
    q_size = 0;
}

//front:
template <typename T>
T queueArr<T>::Front() {
    //check and display if the queue is empty
    if(Empty()) {
        std::cout << "The queue is empty\n";
        return T();
    }

    //return the front item
    return q_array[q_front];
}

//back:
template <typename T>
T queueArr<T>::Back() {
    //check and display if the queue is empty
    if(Empty()) {
        std::cout << "The queue is empty\n";
        return T();
    }

    //return the back item
    return q_array[q_back];
}

//size:
template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}

//enqueue:
template <typename T>
void queueArr<T>::Enqueue(T newData) {
    //check if the queue if full
    if(Full()) {
        std::cout << "Queue is full" << std::endl;
        return;
    }

    //compute for the q_back of the queue array
    q_back = (q_back + 1) % q_capacity;
    // 5 > 0, 6 > 1, 7 > 2, clue:use modulo

    //assign the new value to the back of the queue array
    q_array[q_back] = newData;

    //increment the q_size
    q_size++;
}

//dequeue:
template <typename T>
void queueArr<T>::Dequeue() {
    //check if its empty
    if(Empty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    //compute for the q_front to move it circulary
    q_front = (q_front + 1) % q_capacity;

    //decrement the q_size
    q_size--;
}

//copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr &other) {
    //copy properties from the other
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    //allocate new memory for the array
    q_array = new T[q_capacity];

    //copy the elements from the other queue
    for (size_t i = 0; i < q_size; i++) {
        size_t index = (q_front + q_back) % q_capacity;
        q_array[index] = other.q_array[index];
    }
}

//copy assignment operator
template <typename T>
queueArr<T> &queueArr<T>::operator=(const queueArr<T> &other) {
    if (this != &other) {
        //clean up existing memory
        delete [] q_array;

        //copy properties from the other
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        //allocate new memory for the array
        q_array = new T[q_capacity];

        //copy the elements from the other queue
        for (size_t i = 0; i < q_size; i++) {
            size_t index = (q_front + q_back) % q_capacity;
            q_array[index] = other.q_array[index];
        }
    }
    return *this;
}

#endif
