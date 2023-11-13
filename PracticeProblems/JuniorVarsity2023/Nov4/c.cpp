#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int greedy(vi denominations, int v, int n) {
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        res += v / denominations[i];
        v %= denominations[i];
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vi denominations(n);
    for (int i = 0; i < n; i++) cin >> denominations[i];

    int highest = denominations[n - 1] + denominations[n - 2];
    
    int dp[n][highest];

    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    for (int v = 1; v < highest; v++)
        dp[0][v] = dp[0][v - denominations[0]] + 1;

    for (int i = 1; i < n; i++) {
        for (int v = 1; v < highest; v++) {
            dp[i][v] = min(dp[i][v - denominations[i]] + 1, dp[i - 1][v]);
        }
    }

    for (int v = 1; v < highest; v++) {
        if (greedy(denominations, v, n) != dp[n - 1][v]) {
            cout << "non-canonical" << endl;
            return 0;
        }
    }

    cout << "canonical" << endl;
    return 0;
}