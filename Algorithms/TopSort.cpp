#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool topSortHelper(stack<int>& s, vvi& graph, int v,
    vector<bool>& visited, vector<bool>& current) {
    visited[v] = current[v] = true;

    for (int next : graph[v]) if (current[next] || !visited[next] && 
        !topSortHelper(s, graph, next, visited, current)) return false;

    s.push(v);
    current[v] = false;
    return true;
}

vi topSort(int v, vvi& graph) {
    stack<int> s;
    vi result;
    vector<bool> visited(v), current(v);

    for (int i = 0; i < v; i++)
        if (!visited[i] && !topSortHelper(s, graph, i, visited, current)) return {};

    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main() {
    int v = 6;
    vvi graph(v);
    graph[5].push_back(2);
    graph[2].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    vector<int> result = topSort(v, graph);
    for (int num : result) cout << num << " "; cout << endl;
    vector<int> answer = {5, 4, 2, 3, 1, 0};
    assert(result.size() == answer.size());

    for (int i = 0; i < result.size(); i++) assert(result[i] == answer[i]);

    graph[2].push_back(5);
    result = topSort(v, graph);
    assert(result.size() == 0);
}