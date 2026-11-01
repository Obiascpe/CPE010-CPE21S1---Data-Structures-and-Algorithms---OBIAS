#include <iostream>
#include "HOA5p1_ILOB_Arr.h"

int main() {
    //create and object queue
    queueArr<int> q(6);
    q.Enqueue(1);
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Enqueue(2);
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Enqueue(3);
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Enqueue(4);
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Enqueue(5);
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Enqueue(6);
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Enqueue(7);
    q.Dequeue();
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Dequeue();
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Dequeue();
    std::cout << "q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;
    q.Clear();

    queueArr<int> q2(q);

    std::cout << "\nCopy Constructor" << std::endl;
    std::cout << "q2_front: " << q2.Front() << " q2_back: " << q2.Back() << " q2_size: " << q2.Size() << std::endl;
    queueArr<int> q3(6);

    q3 = q;
    std::cout << "\nCopy Assignment Operator" << std::endl;
    std::cout << "q3_front: " << q3.Front() << " q3_back: " << q3.Back() << " q3_size: " << q3.Size() << std::endl;

    return 0;
}

