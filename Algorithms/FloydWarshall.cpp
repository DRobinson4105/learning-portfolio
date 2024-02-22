#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
ll INF = 1e15;

vvl floydWarshall(vvl graph) {
    int n = graph.size();

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (graph[i][k] != INF && graph[k][j] != INF)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    return graph;
}

int main() {
    int n;
    cin >> n;

    vvl graph(n, vl(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> graph[i][j];

    vvl dist = floydWarshall(graph);

    for (vl row : dist) {
        for (int cell : row)
            cout << cell << " ";
            
        cout << endl;
    }
    return 0;
}