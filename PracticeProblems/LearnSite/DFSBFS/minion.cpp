#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool dfs(vvi graph, unordered_set<int> used, int curr, int target) {
    if (curr == target)
        return true;
    
    used.insert(curr);

    for (int connected : graph[curr]) {
        if (used.count(connected)) continue;
        if (dfs(graph, used, connected, target)) return true;
    }

    return false;
}
int main() {
    int m; cin >> m;

    for (int z = 0; z < m; z++) {
        unordered_set<string> trials;
        unordered_set<int> used;
        int t; cin >> t;
        
        for (int i = 0; i < t; i++) {
            string s; cin >> s;
            trials.insert(s);
        }

        int n, e; cin >> n >> e;
        vvi graph(n);
        
        for (int i = 0; i < e; i++) {
            int a, b; cin >> a >> b;
            string s; cin >> s;

            if (trials.count(s)) continue;

            graph[a].push_back(b);
        }

        cout << dfs(graph, used, 0, n - 1) << endl;
    }

    return 0;
}