#ifndef CPE010_ILOA_GRAPH_H
#define CPE010_ILOA_GRAPH_H

#include <iostream>

// Stores adjacency list items
struct adjNode {
    int val, cost;
    adjNode* next;
};

// Structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};

class DiaGraph {
private:
    int N; // Number of nodes in the graph
    adjNode* getAdjListNode(int value, int weight, adjNode* head);

public:
    adjNode** head; // Adjacency list as array of pointers

    DiaGraph(graphEdge edges[], int n, int N);
    ~DiaGraph();
};

void display_AdjList(adjNode* ptr, int i);

#endif // CPE010_ILOA_GRAPH_H