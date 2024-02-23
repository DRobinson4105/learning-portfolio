#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi topSort(vvi graph, int v){
    vi inDegree(v, 0);
    int count = 0;
    vi result;
    queue<int> q;

    for (vi outgoing : graph)
        for (int next : outgoing)
            inDegree[next]++;

    for (int i = 0; i < v; i++)
        if (inDegree[i] == 0) q.push(i);
 
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        result.push_back(curr);
        count++;
    
        for (int next : graph[curr])
            if (--inDegree[next] == 0) q.push(next);
    }
 
    if (count != v) return {};
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
    graph[5].push_back(4);
    graph[4].push_back(2);
    graph[1].push_back(0);

    vector<int> result = topSort(graph, v);
    for (int num : result) cout << num << " "; cout << endl;
    vector<int> answer = {5, 4, 2, 3, 1, 0};
    assert(result.size() == answer.size());

    for (int i = 0; i < result.size(); i++) assert(result[i] == answer[i]);

    graph[2].push_back(5);
    result = topSort(graph, v);
    assert(result.size() == 0);
}