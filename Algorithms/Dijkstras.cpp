#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
ll INF = 1e15;

vector<ll> dijkstras(vector<vector<pair<int, ll>>>& graph, int n, int src) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<ll> dist(n, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();

        for (auto [v, w]: graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}



int main() {
    vector<vector<pair<int, ll>>> graph = {
        {{1, 2}, {2, 4}},
        {{3, 7}},
        {{3, 1}},
        {{4, 3}},
        {}
    };

    vector<ll> dist = dijkstras(graph, 5, 0);

    for (ll num : dist) cout << num << " ";
    cout << endl;
    // answer should be 0 2 4 5 8
}