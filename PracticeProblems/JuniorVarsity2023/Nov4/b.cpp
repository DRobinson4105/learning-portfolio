#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, f, s, t;

int dfs(vvi roads, int n, bool flightAvailable, vvi flights, int s, int t, vi visited, vi dp) {
    if (s == t) {
        return 0;
    }
    if (dp[s] != -1) return dp[s];

    int best = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (visited[i] || i == s) continue;

        visited[i] = 1;
        if (flightAvailable && flights[s][i])
            best = min(best, dfs(roads, n, false, flights, i, t, visited, dp));

        if (roads[s][i] != INT_MAX)
            best = min(best, roads[s][i] + dfs(roads, n, flightAvailable, flights, i, t, visited, dp));

        visited[i] = 0;
    }

    return dp[s] = best;
}

int main() {
    cin >> n >> m >> f >> s >> t;

    vvi roads(n, vi(n, INT_MAX));
    vvi flights(n, vi(n, 0));
    vi visited(n, 0);
    vi dp(n, -1);

    for (int road = 0; road < m; road++) {
        int i, j, c;
        cin >> i >> j >> c;

        int best = c;
        best = min(roads[i][j], best);
        best = min(roads[j][i], best);
        roads[i][j] = roads[j][i] = best;
    }

    for (int flight = 0; flight < f; flight++) {
        int u, v;
        cin >> u >> v;
        flights[u][v] = 1;
    }

    visited[s] = 1;

    cout << dfs(roads, n, true, flights, s, t, visited, dp) << endl;

    return 0;
}