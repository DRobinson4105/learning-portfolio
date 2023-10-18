#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> dp;

int compute(int n) {
    if (n == 1) return 3;

    if (dp.find(n) != dp.end()) return dp[n];

    return dp[n] = n * (n + 1) * (n + 2) / 2 + compute(n - 1);
}

int main() {
    int N;
    cin >> N;

    for (int num = 1; num <= N; num++) {
        int n;
        cin >> n;
        cout << num << " " << n << " ";

        cout << compute(n) << endl;
    }
    return 0;
}