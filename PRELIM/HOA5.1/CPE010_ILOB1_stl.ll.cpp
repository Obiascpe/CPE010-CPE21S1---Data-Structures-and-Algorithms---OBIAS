#include <iostream>
#include "HOA5p1_ILOB_LL.h"

int main() {

    qNode<char> *front =nullptr;
    qNode<char> *back = nullptr;

    std::cout << "Current Queue: ";
    enqueue(&front, &back, 'J');
    enqueue(&front, &back, 'A');
    enqueue(&front, &back, 'V');
    enqueue(&front, &back, 'E');
    display(front);
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data << std::endl;

    return 0;
}