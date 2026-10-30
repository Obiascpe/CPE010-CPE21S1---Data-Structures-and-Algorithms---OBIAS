#ifndef Circular_LL_H
#define Circular_LL_H

#include <iostream>

template <typename T>
class CircularList {
public:
    T data;
    CircularList<T>* next = nullptr;
};

//creating a node
template <typename T>
CircularList<T>* new_Node(T newData) {

    //dynamically allocate memory for a new node
    CircularList<T>* newNode = new CircularList<T>;

    //store the data in the node
    newNode->data = newData;

    //since this is a new node, it points to itself
    newNode->next = newNode;

    return newNode;
}

//Traversal
template <typename T>
void CllTraverse(CircularList<T>* currentHead) {

    if (currentHead == nullptr) {
        std::cout << "Playlist is Empty." << std::endl;
        return;
    }

    CircularList<T>* currentNode = currentHead;

    do {
        std::cout << currentNode->data << " -> ";
        currentNode = currentNode->next;
    } while (currentNode != currentHead);
    std::cout << "Loop back to:" << currentNode->data;
    std::cout << std::endl << std::endl;
}

//Insertion at Head
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

//Insertion at End
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

// General Insertion
template <typename T>
void CllgeneralInsert(T newData, CircularList<T>* prevNode) {

    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be null." << std::endl;
        return;
    }

    CircularList<T>* newNode = new_Node(newData);

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

//Deletion
template <typename T>
void CllDelete(T findData, CircularList<T>*& currentHead) {

    if (currentHead == nullptr)
        return;

    CircularList<T>* currNode = currentHead;
    CircularList<T>* prevNode = nullptr;

    do {

        if (currNode->data == findData) {

            // Delete head node
            if (prevNode == nullptr) {

                CircularList<T>* tail = currentHead;

                while (tail->next != currentHead) {
                    tail = tail->next;
                }

                // Only one node
                if (tail == currentHead) {
                    delete currentHead;
                    currentHead = nullptr;
                    return;
                }

                currentHead = currentHead->next;
                tail->next = currentHead;

                delete currNode;
                return;
            }

            // Delete middle or last node
            prevNode->next = currNode->next;
            delete currNode;
            return;
        }

        prevNode = currNode;
        currNode = currNode->next;

    } while (currNode != currentHead);

    std::cout << "Song not found." << std::endl;
}

//Delete Entire List
template <typename T>
void CllDeleteList(CircularList<T>*& currentHead) {

    if (currentHead == nullptr)
        return;

    CircularList<T>* currNode = currentHead->next;

    while (currNode != currentHead) {

        CircularList<T>* temp = currNode;
        currNode = currNode->next;

        delete temp;
    }

    delete currentHead;
    currentHead = nullptr;
}

#endif