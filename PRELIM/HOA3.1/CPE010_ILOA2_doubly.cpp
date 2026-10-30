#include <iostream>
#include "CPE010_ILOA2_doubly.h"

int main() {
    #ifndef Circular_LL_H
#define Circular_LL_H

#include <iostream>

template <typename T>
class CircularList {
public:
    T data;
    CircularList<T>* next = nullptr;
};

// Creating a node
template <typename T>
CircularList<T>* new_Node(T newData) {

    // dynamically allocate memory for a new node
    CircularList<T>* newNode = new CircularList<T>;

    // store the data in the node
    newNode->data = newData;

    // since this is a new node, it points to itself
    newNode->next = newNode;

    return newNode;
}

// Traversal
template <typename T>
void CllTraverse(CircularList<T>* currentHead) {

    if (currentHead == nullptr) {
        std::cout << "Playlist is Empty." << std::endl;
        return;
    }

    CircularList<T>* currentNode = currentHead;

    do {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    } while (currentNode != currentHead);

    std::cout << std::endl << std::endl;
}

// Insertion at Head
template <typename T>
void CllInsertHead(T newData, CircularList<T>*& currentHead) {

    CircularList<T>* newNode = new_Node(newData);

    if (currentHead == nullptr) {
        currentHead = newNode;
        return;
    }

    CircularList<T>* tail = currentHead;

    while (tail->next != currentHead) {
        tail = tail->next;
    }

    newNode->next = currentHead;
    tail->next = newNode;
    currentHead = newNode;
}

// Insertion at End
template <typename T>
void CllInsertEnd(T newData, CircularList<T>*& currentHead) {

    CircularList<T>* newNode = new_Node(newData);

    if (currentHead == nullptr) {
        currentHead = newNode;
        return;
    }

    CircularList<T>* tail = currentHead;

    while (tail->next != currentHead) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = currentHead;
}
}