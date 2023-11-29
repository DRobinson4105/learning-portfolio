#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

double distance(pii a, pii b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double shortestPath(vpii graph, vvb blocked, int n) {
    vi perm(n - 1);
    double minPathLength = INT16_MAX;

    for (int i = 0; i < n - 1; i++)
        perm[i] = i + 1;

    do {
        double pathLength = 0;
        int curr = 0;

        for (int next : perm) {
            if (blocked[curr][next]) {
                pathLength = INT16_MAX;
                break;
            }
            pathLength += distance(graph[curr], graph[next]);
            curr = next;
        }
        minPathLength = min(minPathLength, pathLength);
    } while (next_permutation(perm.begin(), perm.end()));

    return minPathLength + 120 * (n - 1);
}

int main() {
    int n;
    cin >> n;

    for (int park = 0; park < n; park++) {
        int r, b;
        cin >> r >> b;

        vpii graph(r + 1); vvb blocked(r + 1, vb(r + 1, false));
        graph[0] = {0, 0};

        for (int i = 1; i <= r; i++)
            cin >> graph[i].first >> graph[i].second;
        
        for (int i = 0; i < b; i++) {
            int x, y; cin >> x >> y;
            blocked[x][y] = blocked[y][x] = true;
        }
            
        double sum = shortestPath(graph, blocked, r + 1);
        sum *= 1000;
        sum = round(sum);
        sum /= 1000;
        if (sum >= INT16_MAX)
            cout << "Jimmy should plan this vacation a different day." << endl;
        else
            cout << "Jimmy can finish all of the rides in " << sum << " seconds." << endl;
    }

    return 0;
}