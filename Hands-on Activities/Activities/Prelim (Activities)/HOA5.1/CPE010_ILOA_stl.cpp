#include <iostream>
#include <queue>

//display function
void display(std::queue<char> r);

int main() {

    std::queue<char> q;
    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');

    //display
    std::cout << "Display: ";
    display(q);

    //empty
    std::cout << "Queue is empty? (y/n): " << q.empty();
    std::cout << '\n';

    //size
    std::cout << "Queue size: " << q.size();
    std::cout << '\n';

    //front
    std::cout << "Front queue: " << q.front();
    std::cout << '\n';

    //back
    std::cout << "Back queue: " << q.back();
    std::cout << '\n';

    //pop
    std::cout << "Popping the front of queue: " << q.front();
    q.pop();
    std::cout << '\n';

    //display
    std::cout << "Display after popping: ";
    display(q);

    //push another element
    std::cout << "Pushing another element: 1";
    q.push('1');
    std::cout << '\n';

    //display
    std::cout << "Display after pushing: ";
    display(q);

    //delete the queue
    while (!q.empty()) {
        q.pop();
    }

    //empty
    std::cout << "Queue is empty? (y/n): " << q.empty();
    std::cout << '\n';

    return 0;
}

void display(std::queue<char> r) {
    //create a copy of the queue
    std::queue<char> c = r;

    while (!c.empty()) {
        std::cout << c.front() << " ";
        c.pop();
    }
    std::cout << '\n';
}