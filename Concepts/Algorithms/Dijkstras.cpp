#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V;

    list<pii>* adj;

    public:
        Graph(int V) {
            this->V = V;
            adj = new list<pii>[V];
        }

        void addEdge(int u, int v, int w) {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        vector<int> shortestPath(int src) {
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            vector<int> dist(this->V, INT_MAX);

            pq.push(make_pair(0, src));
            dist[src] = 0;

            while (!pq.empty()) {
                int u = pq.top().second; pq.pop();

                for (list<pii>::iterator i = this->adj[u].begin(); i != this->adj[u].end(); i++) {
                    int v = (*i).first;
                    int w = (*i).second;

                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }

            return dist;
        }
};