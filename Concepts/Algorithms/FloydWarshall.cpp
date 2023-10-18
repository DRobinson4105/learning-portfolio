#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > floydWarshall(vector<vector<int> > graph) {
    int n = graph.size();

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    return graph;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > graph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> graph[i][j];

    vector<vector<int> > dist = floydWarshall(graph);

    for (vector<int> row : dist) {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }
    return 0;
}