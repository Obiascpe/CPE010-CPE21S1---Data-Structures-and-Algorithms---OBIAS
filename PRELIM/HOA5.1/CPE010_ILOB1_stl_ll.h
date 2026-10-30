//main.h
#ifndef OBIAS_HOA5P1_ILOB_H
#define OBIAS_HOA5P1_ILOB_H


template <typename T>
class qNode {
public:
    T data;
    qNode* next;
};


//creating a new node
template <typename T>
qNode<T>* new_node(T newData) {
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}


template <typename T>
void enqueue(qNode<T> **frontPtr, qNode<T> **backPtr, T newData) {
    //create a new node
    qNode<T> *newNode = new_node<T>(newData);


    //inserting to an empty queue
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }


    //inserting an item into a non empty queue
    (*backPtr)->next = newNode; //point the backPtr next to the newNode
    (*backPtr) = newNode;
}


template <typename T>
void dequeue(qNode<T> **frontPtr, qNode<T> **backPtr) {
    //create a temporary node to store the node to be deleted
    qNode<T> *deleteNode = nullptr;
    deleteNode = (*frontPtr);


    //check if the queue is only 1 node
    if ((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }


    //deleting of the node
    (*frontPtr) = deleteNode->next;
    delete deleteNode;
}


//display all elements in the list
template <typename T>
void display(qNode<T>* front) {
    //create a temporary node
    qNode<T> *displayNode = front;




    while (displayNode != nullptr) {
        std::cout << displayNode->data;
        if (displayNode->next != nullptr)
            std::cout << " -> ";


        displayNode = displayNode ->next;
    }


    std::cout << std::endl;
}


//return the front variable


#endif
