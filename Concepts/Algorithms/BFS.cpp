  #include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data, numNeighbors;
    vector<int> neighbors;

    Node(int val) : data(val), numNeighbors(0) {}
};

bool bfs(vector<Node> nodes, vector<bool> visited, int start, int targetNode) {
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == targetNode)
            return true;

        for (int node : nodes[curr].neighbors) {
            if (!visited[node])
                q.push(node);
        }
    }

    return false;
}