#include <iostream>
#include "CPE010_ILOA1_singly.h"

int main() {
    //create the node pointing to null
    SingleList<char> *head = NULL;
    SingleList<char> *second = NULL;
    SingleList<char> *third = NULL;
    SingleList<char> *fourth = NULL;
    SingleList<char> *fifth = NULL;
    SingleList<char> *last = NULL;

    //create the nodes
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;
    fifth = new SingleList<char>;
    last = new SingleList<char>;

    head->data = 'C'; //stores the 'C' in the first node
    head->next = second; //first node pointing to second

    second->data = 'P'; //stores the 'P' in the second node
    second->next = third; //second node pointing to third

    third->data = 'E'; //stores the 'E' in the third node
    third->next = fourth; //third node pointing to fourth

    fourth->data = '1'; //stores the '1' in the fourth node
    fourth->next = fifth; //fourth node pointing to fifth

    fifth->data = '0'; //stores the '0' in the fifth node
    fifth->next = last; //fifth node pointing to last node

    last->data = '1'; //stores the '1' in the last node
    last->next = nullptr; //last node pointing to null

    //Traverse the list by passing the head of the created list into the function.
    std::cout <<"Traverse the original list: " << std::endl;
    listTraversal(head);

    //Insert the element ‘G’ at the start of the list to replace the current node. Output should now show “GCPE101”.
    sllinsertHead('G', &head);
    std::cout <<"\nInsert G at the start: " << std::endl;
    listTraversal(head);

    //Insert an element “E” with the previous node element being “P”. Output should now show “GCPEE101”.
    sllGeneralInsertion('E', head->next->next);
    std::cout <<"\nInsert E after P: " << std::endl;
    listTraversal(head);

    //Delete the node containing the element C.
    sllDelete('C', &head);
    std::cout <<"\nDelete C: " << std::endl;
    listTraversal(head);

    //Delete the node containing the element P.
    sllDelete('P', &head);
    std::cout <<"\nDelete P: " << std::endl;
    listTraversal(head);

    //Show the elements in the list. Output should be “GEE101”.
    std::cout <<"\nFinal list: " << std::endl;
    listTraversal(head);

    return 0;
}