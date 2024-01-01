#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

struct Position {
    int x, y, moves;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    int n, m; cin >> n >> m;
    vvi grid(n, vi(m));
    unordered_map<string, int> bestMoves;
    unordered_set<string> used;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            grid[i][j] = s[j] - '0';
    }

    vvb visited(n, vb(m, false));
    queue<Position> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Position p = q.front(); q.pop();
        if (p.x == n - 1 && p.y == m - 1) {
            cout << p.moves << endl;
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i] * grid[p.x][p.y];
            int ny = p.y + dy[i] * grid[p.x][p.y];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, p.moves + 1});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}