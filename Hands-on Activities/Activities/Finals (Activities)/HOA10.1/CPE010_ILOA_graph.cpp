#include <iostream>
#include "CPE010_ILOA_graph.h"

// Insert new nodes into adjacency list from given graph
adjNode* DiaGraph::getAdjListNode(int value, int weight, adjNode* head) {
    adjNode* newNode = new adjNode;
    newNode->val = value;
    newNode->cost = weight;
    newNode->next = head; // Point new node to current head
    return newNode;
}

// Constructor
DiaGraph::DiaGraph(graphEdge edges[], int n, int N) {
    head = new adjNode*[N]();
    this->N = N;

    // Initialize head pointer for all vertices
    for (int i = 0; i < N; ++i) {
        head[i] = nullptr;
    }

    // Construct directed graph by adding edges to it
    for (int i = 0; i < n; i++) {
        int start_ver = edges[i].start_ver;
        int end_ver = edges[i].end_ver;
        int weight = edges[i].weight;

        // Insert at the beginning
        adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
        head[start_ver] = newNode;
    }
}

// Destructor (Properly frees dynamically allocated memory)
DiaGraph::~DiaGraph() {
    for (int i = 0; i < N; i++) {
        adjNode* current = head[i];
        while (current != nullptr) {
            adjNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    delete[] head;
}

// Print all adjacent vertices of a given vertex
void display_AdjList(adjNode* ptr, int i) {
    while (ptr != nullptr) {
        std::cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

// Main execution function for ILO A
int main() {
    // Graph edges array: (x, y, w) -> edge from x to y with weight w
    graphEdge edges[] = {
        {0, 1, 2}, {0, 2, 4}, {1, 4, 3}, {2, 3, 2}, {3, 1, 4}, {4, 3, 3}
    };

    int N = 6; // Number of vertices in the graph
    int n = sizeof(edges) / sizeof(edges[0]); // Number of edges

    // Construct graph
    DiaGraph diagraph(edges, n, N);

    // Print adjacency list representation
    std::cout << "Graph adjacency list " << std::endl;
    std::cout << "(start_vertex, end_vertex, weight):" << std::endl;
    for (int i = 0; i < N; i++) {
        display_AdjList(diagraph.head[i], i);
    }

    return 0;
}