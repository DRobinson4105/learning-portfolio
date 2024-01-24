#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int shortestPath(int src, int v, list<pii>* adj) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(v, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
		    int u = pq.top().second; pq.pop();

				list<pii>::iterator i;
	      for (i = adj[u].begin(); i != adj[u].end(); i++) {
		    int v = (*i).first;
            int w = (*i).second;

            if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
		    }
		}
    }

	return dist[v - 1];
}

int longestPath(int src, int v, list<pii>* adj) {
		priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(v, 0);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
		    int u = pq.top().second; pq.pop();

				list<pii>::iterator i;
	      for (i = adj[u].begin(); i != adj[u].end(); i++) {
		        int v = (*i).first;
            int w = (*i).second;

            if (dist[v] < dist[u] + w) {
				dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
		    }
		}
    }  

	return dist[v - 1];
}

int main() {
    int c; cin >> c;
    
    while (c--) {
        int v, e; cin >> v >> e;

        list<pii>* adj = new list<pii>[v];

        for (int i = 0; i < e; i++) {
            int s, d, m; cin >> s >> d >> m;
            adj[s].push_back(make_pair(d, m));
        }

        cout << shortestPath(0, v, adj) << " " << longestPath(0, v, adj) << endl;
    }

    return 0;
}