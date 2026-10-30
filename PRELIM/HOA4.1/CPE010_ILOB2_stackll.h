#ifndef OBIAS_CPE010_HOA4_MAINB2_H
#define OBIAS_CPE010_HOA4_MAINB2_H
#include <iostream>
#include <ostream>

//class node that contains data and the next
template <typename T>
class Node {
    public:
    T data;     //value that we need to store
    Node *next; //pointer to the next node
};

//global pointer for the top of the stack
template <typename T>
Node<T> *head = nullptr; //pointer

//operations for the stack


//push
template <typename T>
void push(T newData) {
    //create a new node and assign the newData
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;

    //new node points to current top, then becomes the new top
    newNode->next = head<T>;
    head<T> = newNode;
}

//pop
template <typename T>
T pop() {
    //check if the stack is empty
    if (head<T> == nullptr) {
        std::cout << "Stack Overflow" << std::endl;
    }

    //save the current top node
    Node<T> *temp = head<T>;

    //store its data
    T tempVal = temp->data;

    //move the head to the next node
    head<T> = head<T>->next;

    //free the removed node
    delete temp;

    //return the removed value
    return tempVal;
}

//isEmpty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

//top
template <typename T>
void Top() {
    //error catching:
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow" << std::endl;
        return;
    }

    //display the top node
    std::cout << "Top of Stack: "<< head<T>->data << std::endl;
}

//displayAll
template <typename T>
void displayAll() {
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow." << std::endl;
        return;
    }

    std::cout << "Stack: " << std::endl;
    Node<T> *temp = head<T>;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

    std::cout << std::endl;
}

#endif