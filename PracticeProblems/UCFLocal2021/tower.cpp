#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

int time(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + (y2 - y1) * (y2 - y1);
}

using namespace std;

int best = INT_MAX;

void solve(int n, int k, vector<int> points, int curr, int count) {
    if (curr == n - 1) {
        count += time(points[curr], curr + 1, points[n - 1], n);
        best = min(best, count);
        return;
    }

    for (int i = 1; i <= k && curr + i < n; i++)
        solve(n, k, points, curr + i, count + time(points[curr], curr + 1, points[curr + i], curr + i + 1));
}
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> points(n);
    for (int i = 0; i < n; i++) cin >> points[i];

    solve(n, k, points, 0, 0);
    cout << best << endl;
    return 0;
}