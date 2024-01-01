#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int dirX[4] = {0, 0, 1, -1};
const int dirY[4] = {1, -1, 0, 0};

int convToInt(const vvi& grid) {
    int res = 0;
    for (int i = 0; i < 9; i++)
        res = res * 10 + grid[i / 3][i % 3];
    return res;
}

vvi intToGrid(int state) {
    vvi grid(3, vi(3));
    for (int i = 8; i >= 0; i--) {
        grid[i / 3][i % 3] = state % 10;
        state /= 10;
    }
    return grid;
}

vector<int> getReverseMoves(int state) {
    vector<int> moves;
    vvi grid = intToGrid(state);
    int x, y;
    for (x = 0; x < 3; x++)
        for (y = 0; y < 3; y++)
            if (grid[x][y] == 0) goto found;
    found:

    for (int d = 0; d < 4; d++) {
        int nx = x + dirX[d], ny = y + dirY[d];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            swap(grid[x][y], grid[nx][ny]);
            moves.push_back(convToInt(grid));
            swap(grid[x][y], grid[nx][ny]);
        }
    }
    return moves;
}

int solvePuzzle(const vvi& initialGrid, unordered_map<int, int>& dist) {
    unordered_set<int> used;
    queue<int> q;
    int initialState = convToInt(initialGrid);
    int solvedState = 123456780;
    q.push(solvedState);
    dist[solvedState] = 0;
    if (dist.count(initialState))
        return dist[initialState];

    while (!q.empty()) {
        int currentState = q.front();
        q.pop();

        if (currentState == initialState)
            return dist[currentState];

        used.insert(currentState);

        for (int nextState : getReverseMoves(currentState)) {
            if (dist.find(nextState) == dist.end() || dist[nextState] > dist[currentState] + 1)
                dist[nextState] = dist[currentState] + 1;
            if (!used.count(nextState))
                q.push(nextState);
        }
    }
    return -1;
}

int main() {
    unordered_map<int, int> dist;
    int n;
    cin >> n;

    for (int t = 0; t < n; t++) {
        vvi grid(3, vi(3));
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> grid[i][j];

        int result = solvePuzzle(grid, dist);
        cout << result << endl;
    }
    return 0;
}
