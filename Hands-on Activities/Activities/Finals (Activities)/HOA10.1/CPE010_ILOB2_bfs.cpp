#include <iostream>
#include "CPE010_ILOB2_bfs.h"

template <typename T>
void test_BFS() {
    auto G = create_bfs_graph<unsigned>();
    std::cout << "--- BFS Reference Graph ---" << std::endl;
    std::cout << G << std::endl;

    std::cout << "BFS Order of vertices starting from 1: " << std::endl;
    auto bfs_visit_order = breadth_first_search(G, 1);
    for (auto v : bfs_visit_order) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    using T = unsigned;
    test_BFS<T>();
    return 0;
}