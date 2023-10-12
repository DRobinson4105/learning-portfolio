#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int best = INT_MAX;

void solve(vector<pair<int, int>> shops, vector<int> visited, int R, int C, int F, int S, int count, int currR, int currC) {
    if (R - currR + C - currC <= F) {
        best = min(best, R - currR + C - currC + count);
        return;
    }

    for (int i = 0; i < S; i++) {
        int diffR = abs(currR - shops[i].first);
        int diffC = abs(currC - shops[i].second);
        if (visited[i] || diffR + diffC > F) continue;

        visited[i] = 1;
        solve(shops, visited, R, C, F, S, count + diffR + diffC, shops[i].first, shops[i].second);
    }
}

int main() {
    int R, C, F, S;
    cin >> R >> C >> F >> S;

    vector<pair<int, int>> shops(S);
    for (int i = 0; i < S; i++) {
        cin >> shops[i].first >> shops[i].second;
        shops[i].first--;
        shops[i].second--;
    }

    vector<int> visited(S);
    solve(shops, visited, R - 1, C - 1, F, S, 0, 0, 0);
    cout << best << endl;
}