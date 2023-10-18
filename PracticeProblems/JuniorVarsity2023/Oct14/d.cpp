#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool chipified(vector<vector<int> > pan, int i, int j, int n, int m) {
    if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        return true;

    if (pan[i - 1][j] == 0 || pan[i + 1][j] == 0 || pan[i][j - 1] == 0 || pan[i][j + 1] == 0)
        return true;

    return false;
}

int count = 0;

void solve(vector<vector<int> > pan, vector<pair<int, int> > outer, int n, int m) {
    if (outer.size() == 0) {
        return;
    }

    ::count++;

    vector<pair<int, int> > newOuter;

    for (int i = 0; i < outer.size(); i++) {
        int x = outer[i].first;
        int y = outer[i].second;
        pan[x][y] = 0;

        if (x != 0 && pan[x - 1][y] == 1 && find(outer.begin(), outer.end(), make_pair(x - 1, y)) == outer.end()) {
            pan[x - 1][y] = 0;
            newOuter.push_back(make_pair(x - 1, y));
        }

        if (x != n - 1 && pan[x + 1][y] == 1 && find(outer.begin(), outer.end(), make_pair(x + 1, y)) == outer.end()) {
            pan[x + 1][y] = 0;
            newOuter.push_back(make_pair(x + 1, y));
        }

        if (y != 0 && pan[x][y - 1] == 1 && find(outer.begin(), outer.end(), make_pair(x, y - 1)) == outer.end()) {
            pan[x][y - 1] = 0;
            newOuter.push_back(make_pair(x, y - 1));
        }

        if (y != m - 1 && pan[x][y + 1] == 1 && find(outer.begin(), outer.end(), make_pair(x, y + 1)) == outer.end()) {
            pan[x][y + 1] = 0;
            newOuter.push_back(make_pair(x, y + 1));
        }
    }

    solve(pan, newOuter, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > pan(n, vector<int>(m, 0));
    vector<pair<int, int> > outer;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            if (s[j] == 'X') {
                pan[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pan[i][j] == 1 && chipified(pan, i, j, n, m))
                outer.push_back(make_pair(i, j));
        }
    }

    solve(pan, outer, n, m);
    cout << ::count << endl;
    return 0;
}