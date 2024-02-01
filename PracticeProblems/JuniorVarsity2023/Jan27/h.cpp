#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k, p; cin >> n >> k >> p;
    long long mini = ceil(n / (double)p);
    long long maxi = min((long long)sqrt(n), k);

    vector<long long> res1;
    vector<long long> res2;

    int len1 = 0;
    int len2 = 0;

    for (int i = 1; i <= maxi; i++) {
        if (n % i == 0) {
            if (n / (double)i <= p && i >= n / p) {
                res1.push_back(i);
                len1++;
            }
            long long other = n / i;
            if (i * i != n && other <= k && n / (double)other <= p) {
                res2.push_back(other);
                len2++;
            }
        }
    }

    cout << len1 + len2 << endl;
    for (int i = 0; i < len1; i++)
        cout << res1[i] << endl;
    for (int i = len2 - 1; i >= 0; i--)
        cout << res2[i] << endl;
    return 0;
}

// 6 6 4

// 100000000000 100000000000 100000000000
