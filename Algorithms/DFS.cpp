#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data, numNeighbors;
    vector<int> neighbors;

    Node(int val) : data(val), numNeighbors(0) {}
};

void connectNodes(vector<Node> nodes, int index1, int index2) {
    nodes[index1].neighbors.push_back(index2);
    nodes[index1].numNeighbors++;
    nodes[index2].neighbors.push_back(index1);
    nodes[index2].numNeighbors++;
}

bool dfs(vector<Node> nodes, vector<bool>& visited, int curr, int targetNode) {
    visited[curr] = true;

    if (curr == targetNode)
        return true;

    for (int node : nodes[curr].neighbors) {
        if (!visited[node] && dfs(nodes, visited, node, targetNode))
            return true;
    }

    return false;
}

int main() {
    
    return 0;
}