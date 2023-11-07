#include <iostream>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pii;

int n, m, f, s, t;

class Graph {
    public:
        int V, F;
        list<pii>* adj;
        
        Graph(int V, int F) {
            this->V = V;
            this->F = F;
            adj = new list<pii>[V * (F + 1)];
        }

        void addEdge(int u, int v, int w) {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        void clone() {
            for (int f = 1; f <= this->F; f++) {
                for(int i = 0; i < this->V; i++) {
                    for (list<pii>::iterator j = this->adj[i].begin(); j != this->adj[i].end(); j++) {
                        adj[i + f * V].push_back(make_pair((*j).first + f * V, (*j).second));
                    }
                }
            }
        }

        void addFlight(int f, int u, int v) {
            adj[u].push_back(make_pair(v + f * V, 0));
        }

        ll shortestPath(int src, int t) {
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            vector<ll> dist(this->V * (this->F + 1), LONG_LONG_MAX);

            pq.push(make_pair(0, src));
            dist[src] = 0;

            while (!pq.empty()) {
                int u = pq.top().second; pq.pop();
                int k = 0;
                for (list<pii>::iterator i = adj[u].begin(); i != adj[u].end(); i++) {
                    int v = (*i).first;
                    int w = (*i).second;

                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push(make_pair(dist[v], v));
                    }

                    k++;
                }
            }

            ll lowest = dist[t];

            for (int i = 1; i <= F; i++)
                lowest = min(lowest, dist[t + i * V]);

            return lowest;
        }
};

int main() {
    cin >> n >> m >> f >> s >> t;
    Graph* graph = new Graph(n, f);

    for (int road = 0; road < m; road++) {
        int i, j, c;
        cin >> i >> j >> c;

        graph->addEdge(i, j, c);
    }

    graph->clone();

    for (int flight = 1; flight <= f; flight++) {
        int u, v;
        cin >> u >> v;

        graph->addFlight(flight, u, v);
    }

    // for (int i = 0; i < graph->V * (graph->F + 1); i++) {
    //     cout << i << ":" << endl;
    //     for (list<pii>::iterator j = graph->adj[i].begin(); j != graph->adj[i].end(); j++) {
    //         cout << (*j).first << " " << (*j).second << endl;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << graph->shortestPath(s, t) << endl;

    return 0;
}