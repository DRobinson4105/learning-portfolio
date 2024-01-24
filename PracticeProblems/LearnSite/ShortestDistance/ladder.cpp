#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;

int numDiff(string& s1, string& s2) {
    int res = 0;
    for (int i = 0; i < s1.length(); i++)
        if (s1[i] != s2[i]) res++;

    return res;
}

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

	return dist[1];
}

int main() {
    int n; cin >> n;

    vs dict(n);
    vvi diff(n, vi(n));
	list<pii>* adj = new list<pii>[n + 1];

    for (int i = 0; i < n; i++)
        cin >> dict[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int dif = diff[i][j] = diff[j][i] = numDiff(dict[i], dict[j]);
            if (dif <= 1) {
                adj[i].push_back({ j, 1 });
                adj[j].push_back({ i, 1 });
            }
        }
    }

	int original = shortestPath(0, n, adj);
    int len = dict[0].length();
    int bestVal = original;
    string bestStr = "0";

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (diff[i][j] == 2) {
                string s = dict[i];
                bool useSecond = false;
                for (int k = 0; k < len; k++) {
                    if (dict[i][k] != dict[j][k]) {
                        if (dict[i][k] > dict[j][k])
                            s[k] = dict[j][k];
                        else useSecond = true;
                        break;
                    }
                }
                
                if (useSecond) {
                    for (int k = len - 1; k >= 0; k--) {
                        if (dict[i][k] != dict[j][k]) {
                            s[k] = dict[j][k];
                            break;
                        }
                    }
                }

                unordered_set<int> used;
                for (int i = 0; i < n; i++) {
                    int d = numDiff(dict[i], s);
                    if (d <= 1) {
                        adj[i].push_back({ n, 1 });
                        adj[n].push_back({ i, 1 });
                        used.insert(i);
                    }
                }

                int curr = shortestPath(0, n + 1, adj);
                if (curr < bestVal || (curr == bestVal && bestStr.compare("0") && s.compare(bestStr))) {
                    bestVal = curr;
                    bestStr = s;
                }

                for (int num : used) {
                    adj[num].pop_back();
                }
                adj[n].clear();
            }
        }
    }

    cout << bestStr << endl << (bestVal == INT_MAX ? -1 : bestVal) << endl;
    return 0;
}