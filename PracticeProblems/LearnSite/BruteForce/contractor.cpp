#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int days, price;
    int c; cin >> c;

    for (int cases = 0; cases < c; cases++) {
        int n, d; cin >> n >> d;

        vvi dp(n + 1, vi(d + 1, 0));

        for (int i = 1; i <= n; i++) {
            cin >> days >> price;

            for (int j = 1; j <= d; j++) {
                dp[i][j] = (days > j) ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - days] + price);
            }
        }

        cout << dp[n][d] << endl;
    }

    return 0;
}