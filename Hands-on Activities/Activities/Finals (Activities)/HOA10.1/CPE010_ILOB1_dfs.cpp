#include <iostream>
#include "CPE010_ILOB1_dfs.h"

template <typename T>
void test_DFS() {
    auto G = create_dfs_graph<unsigned>();
    std::cout << "--- DFS Reference Graph ---" << std::endl;
    std::cout << G << std::endl;

    std::cout << "DFS Order of vertices starting from 1: " << std::endl;
    auto dfs_visit_order = depth_first_search(G, 1);
    for (auto v : dfs_visit_order) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    using T = unsigned;
    test_DFS<T>();
    return 0;
}