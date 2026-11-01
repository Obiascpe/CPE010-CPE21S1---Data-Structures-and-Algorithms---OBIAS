#ifndef OBIAS_CPE010_ILOA1_SINGLY_H
#define OBIAS_CPE010_ILOA1_SINGLY_H

template <typename T> //makes the class accept any data type
class SingleList{
    public:
    T data; //data of the node
    SingleList<T> *next = nullptr; //stores the address of the next node
};

template <typename T>
void listTraversal(SingleList<T>* head){

    while(head != nullptr){
        std::cout <<head->data;

        //check if the next line is not equal to NULL
        if (head->next != nullptr){
            std::cout << " -> ";
        }

        //move to the next node
        head = head->next;
    }

    //go to the next line after displaying the list
    std::cout<<std::endl;
}

template <typename T>
void sllinsertHead(T newdata, SingleList<T>** currentHead){

    //create a new node
    SingleList<T>* newNode = new SingleList<T>;

    //store the new data in the node
    newNode->data = newdata;

    //point the new node to the current head
    newNode->next = *currentHead;

    //make the new node the new head
    *currentHead = newNode;
}

template <typename T>
void sllGeneralInsertion(T newdata, SingleList<T> * prevNode){

    //check if the previous node is null
    if(prevNode==nullptr){
        std::cout<<"The previous node is null." << std::endl;
        return;
    }

    //Allocate new node
    SingleList<T>* newNode = new SingleList<T>;

    //Store data in the new node
    newNode->data = newdata;

    //Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;

    //points previous node to the new node
    prevNode->next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SingleList<T>** head){

    //Allocate new node
    SingleList<T>* newNode = new SingleList<T>;

    //Dereference to the head node
    SingleList<T>* currentNode = *head;

    //Store data in new node
    newNode->data = newData;

    //Point next of new node to NULL
    newNode->next = nullptr;

    //check if the list is empty
    if(currentNode == nullptr){
        *head = newNode;
        return;
    }

    //Traverse the list until next of the node is null
    while(currentNode->next != nullptr){

        //Iteration going to one node to another
        currentNode = currentNode->next;
    }

    //connect the last node to the new node
    currentNode->next = newNode;
}

template <typename T>
void sllDelete(T findData, SingleList<T>** head){

    //check if the list is empty
    if(*head == nullptr) return;

    //create pointers for the current and previous node
    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    //Search for the node:
    while(currNode != nullptr && currNode->data != findData){

        //move the previous node to the current node
        prevNode = currNode;

        //move the current node to the next node
        currNode = currNode->next;
    }

    //if data is not found
    if(currNode == nullptr) return;

    //delete the head node(the head node is the findData)
    if (prevNode == nullptr){
        *head = currNode->next;
    }else{

        //connect the previous node to the next node
        prevNode->next = currNode->next;
    }

    //delete the node
    delete currNode;
}

template <typename T>
void sllDeleteList(SingleList<T>** head){

    //start from the head node
    SingleList<T>* currentNode = *head;

    //delete each node until the end of the list
    while(currentNode != nullptr){

        //temporarily store the current node
        SingleList<T>* temp = currentNode;

        //move to the next node
        currentNode = currentNode->next;

        //delete the current node
        delete temp;
    }

    //make the head null after deleting all nodes
    *head = nullptr;
}

#endif
