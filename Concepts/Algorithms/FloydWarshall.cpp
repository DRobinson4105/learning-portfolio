#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> graph) {
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (vector<int> edge : graph)
        dist[edge[0]][edge[1]] = edge[2];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist;
}

int main() {
    return 0;
}