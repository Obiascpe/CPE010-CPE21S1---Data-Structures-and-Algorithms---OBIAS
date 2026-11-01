#include <iostream>
#include "CPE010_HOA3_ILOB_OBIAS.h"

int main() {
    //music playlist
    CircularList<std::string>* head = new_Node<std::string>("Song1"); //head node
    CircularList<std::string>* second = new_Node<std::string>("Song2"); //second node
    CircularList<std::string>* third = new_Node<std::string>("Song3"); //third node

    head->next = second; //first node pointing second node
    second->next = third; //second node pointing third node
    third->next = head; //third node pointing back to the head

    std::cout << "Initial Playlist" << std::endl;
    CllTraverse(head);

    //insert song at the head
    std::cout << "Inserting 'Song4' at Head" << std::endl;
    CllInsertHead<std::string>("Song4", head);
    CllTraverse(head);

    //insert song at the end
    std::cout << "Inserting 'Song5' at End" << std::endl;
    CllInsertEnd<std::string>("Song5", head);
    CllTraverse(head);

    //insert song after Photograph (second node)
    std::cout << "General Insertion ('Song6' after 'Song2')" << std::endl;
    CllgeneralInsert<std::string>("Song6", second);
    CllTraverse(head);

    //delete a song
    std::cout << "Deleting Song 'Song3'" << std::endl;
    CllDelete<std::string>("Song3", head);
    CllTraverse(head);

    //delete the entire playlist
    std::cout << "Deleting Entire Playlist" << std::endl;
    CllDeleteList(head);

    if (head == nullptr) {
        std::cout << "Playlist successfully deleted and head is null." << std::endl;
    }

    return 0;
}