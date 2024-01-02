#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vb;
typedef vector<vb> vvb;

void dfs(vvb grid, vector<bool>& used, int curr, int k) {
    used[curr] = true;

    for (int i = 0; i < k; i++) {
        if (!grid[curr][i] || used[i]) continue;

        dfs(grid, used, i, k);
    }
}

bool simulate(vvb grid, int city, int k) {
    for (int i = 0; i < k; i++) {
        grid[i][city] = false;
    }

    vector<bool> used(k);
    dfs(grid, used, city == 0 ? 1 : 0, k);

    for (int i = 0; i < k; i++)
        if (!used[i] && i != city) return true;
    
    return false;
}

int main() {
    int n; cin >> n;

    for (int z = 1; z <= n; z++) {
        int k; cin >> k;
        vvb grid(k, vb(k));

        for (int i = 0; i < k; i++) {
            int l; cin >> l;

            for (int j = 0; j < l; j++) {
                int k = 0; cin >> k; k--;
                grid[i][k] = true;
            }
        }

        int c; cin >> c;
        cout << "City #" << z << endl;

        for (int i = 0; i < c; i++) {
            int num; cin >> num; num--;
            cout << (simulate(grid, num, k) ? "yes" : "no") << endl;
        }
        cout << endl;
    }

    return 0;
}