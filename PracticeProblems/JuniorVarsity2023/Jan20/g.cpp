#include <bits/stdc++.h>

using namespace std;

typedef vector<double> vd;

unordered_map<string, double> dp;

double best = 0;

double compute(vd probs, int i, int j, int k) {
    if (i == k) {
        if (j == 0) return 0;
        return j == 0 ? 0 : (pow(j, j / (double)k));
    }

    string str = to_string(i) + " " + to_string(j);

    if (dp.find(str) != dp.end()) return dp[str];

    return dp[str] = probs[i] * compute(probs, i + 1, j + 1, k) + 
                    (1 - probs[i]) * compute(probs, i + 1, j, k);
}
int main() {
    cout << fixed << setprecision(8);
    int n; cin >> n;
    vd probs(n);
    
    for (int i = 0; i < n; i++) {
        cin >> probs[i];
        probs[i] /= 100;
    }

    sort(probs.begin(), probs.end(), [](const double& a, const double& b) {
        return a > b;
    });

    for (int i = 1; i <= n; i++) {
        best = max(best, compute(probs, 0, 0, i));
        dp.clear();
    }

    cout << best << endl;
    return 0;
}