#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int best;
void dfs(vector<int> sandwiches, vvi trades, vector<bool>& used, int curr) {
    used[curr] = true;
    best = max(best, sandwiches[curr]);

    for (int num : trades[curr]) {
        if (used[num]) continue;
        dfs(sandwiches, trades, used, num);
    }
}

int main() {
    int c; cin >> c;

    while (c--) {
        int n, s; cin >> n >> s;

        vector<int> sandwiches(s);
        for (int i = 0; i < s; i++) cin >> sandwiches[i];

        vvi trades(s);
        vector<bool> used(s);

        for (int i = 0; i < n; i++) {
            int d, t; cin >> d >> t; d--;

            for (int j = 0; j < t; j++) {
                int num; cin >> num; num--;
                trades[num].push_back(d);
            }
        }

        best = 0;
        dfs(sandwiches, trades, used, 0);
        cout << best << endl;
    }

    return 0;
}