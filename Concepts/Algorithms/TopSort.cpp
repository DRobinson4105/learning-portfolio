#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

void topologicalSortHelper(
    stack<int>& Stack, list<int> nodes[], 
    int v, bool visited[]
) {
    visited[v] = true;

    for (list<int>::iterator i = nodes[v].begin(); i != nodes[v].end(); i++)
        if (!visited[*i])
            topologicalSortHelper(Stack, nodes, *i, visited);

    Stack.push(v);
}

vector<int> topologicalSort(int v, list<int> nodes[]) {
    stack<int> Stack;
    vector<int> result;

    bool* visited = new bool[v];

    for (int i = 0; i < v; i++)
        visited[i] = false;

    for (int i = 0; i < v; i++)
        if (!visited[i])
            topologicalSortHelper(Stack, nodes, i, visited);

    while (!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }

    delete [] visited;

    return result;
}

int main() {
    int v = 6;
    list<int>* nodes = new list<int>[6];
    nodes[5].push_back(2);
    nodes[5].push_back(0);
    nodes[4].push_back(0);
    nodes[4].push_back(1);
    nodes[2].push_back(3);
    nodes[3].push_back(1);

    vector<int> result = topologicalSort(v, nodes);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;
}