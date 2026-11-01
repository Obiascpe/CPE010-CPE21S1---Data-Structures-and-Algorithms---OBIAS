#ifndef CPE010_ILOB2_BFS_H
#define CPE010_ILOB2_BFS_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

template <typename T>
class Graph;

// Edge structure
template <typename T>
struct Edge {
    size_t src;
    size_t dest;
    T weight;

    inline bool operator<(const Edge<T>& e) const {
        return this->weight < e.weight;
    }
    inline bool operator>(const Edge<T>& e) const {
        return this->weight > e.weight;
    }
};

// Graph class implementation using Edge List
template <typename T>
class Graph {
public:
    Graph(size_t N) : V(N) {}

    auto vertices() const { return V; }
    auto& edges() const { return edge_list; }

    void add_edge(Edge<T>&& e) {
        if (e.src >= 1 && e.src <= V && e.dest >= 1 && e.dest <= V) {
            edge_list.emplace_back(e);
        } else {
            std::cerr << "Vertex out of bounds" << std::endl;
        }
    }

    auto outgoing_edges(size_t v) const {
        std::vector<Edge<T>> edges_from_v;
        for (auto& e : edge_list) {
            if (e.src == v) {
                edges_from_v.emplace_back(e);
            }
        }
        return edges_from_v;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Graph<U>& G);

private:
    size_t V;
    std::vector<Edge<T>> edge_list;
};

// Overload << operator to display graph adjacency
template <typename T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& G) {
    for (size_t i = 1; i <= G.vertices(); i++) {
        os << i << ":\t";
        auto edges = G.outgoing_edges(i);
        for (auto& e : edges) {
            os << "{" << e.dest << ": " << e.weight << "}, ";
        }
        os << std::endl;
    }
    return os;
}

// Breadth-First Search Algorithm
template <typename T>
auto breadth_first_search(const Graph<T>& G, size_t start_vertex) {
    std::queue<size_t> queue;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    queue.push(start_vertex);

    while (!queue.empty()) {
        auto current_vertex = queue.front();
        queue.pop();

        if (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto e : G.outgoing_edges(current_vertex)) {
                if (visited.find(e.dest) == visited.end()) {
                    queue.push(e.dest);
                }
            }
        }
    }
    return visit_order;
}

// Helper function to build reference graph for BFS (ILO B.2)
template <typename T>
auto create_bfs_graph() {
    Graph<T> G(8);
    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;

    edges[1] = {{2, 2}, {5, 3}};
    edges[2] = {{1, 2}, {5, 5}, {4, 1}};
    edges[3] = {{4, 2}, {7, 3}};
    edges[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    edges[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    edges[6] = {{4, 4}, {7, 4}, {8, 1}};
    edges[7] = {{3, 3}, {6, 4}};
    edges[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (auto& i : edges) {
        for (auto& j : i.second) {
            G.add_edge(Edge<T>{i.first, j.first, j.second});
        }
    }
    return G;
}

#endif // CPE010_ILOB2_BFS_H