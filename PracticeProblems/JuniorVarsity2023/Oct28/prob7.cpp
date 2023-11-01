#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int MOD = 10007;
vector<ll> fact(501, 1);
vector<ll> inv(501);

ll modpow(ll b, ll p) {
    ll ans = 1;

    while (p) {
        if (p & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        p >>= 1;
    }

    return ans;
}

void gen_fact() {
    for (int i = 1; i < fact.size(); i++) {
        fact[i] = (fact[i-1] % MOD) * (i % MOD);
    }

    inv[500] = modpow(fact[500], MOD - 2);
    for (int i = 500; i >= 1; i--) {
        inv[i - 1] = (inv[i] * i) % MOD;
    }
}

// int nCr(int n, int r) {
//     if (n == 0 || r == 0) { return 0; }
//     int ans = (fact[n] % MOD) / (fact[r] % MOD);
//         ans /= (fact[n-r] % MOD);
    
//     return ans % MOD;
// }

ll choose(ll n, ll k) {
    ll top = fact[n];
    ll bottom = (inv[k] * inv[n - k]) % MOD;
    return (top * bottom) % MOD;
}

int main() {
    gen_fact();
    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n, k;
        long long int total = 0;
        cin >> n >> k;

        string str;
        cin >> str;

        int size = str.size();
        int numL = 0, currL = 0;

        for (char c : str)
            if (c == 'L') numL++;

        if (numL < 2 * k) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < size && numL - currL >= k; i++) {
            if (str[i] == 'O' && currL >= k) {
                total += (choose(currL, k) * choose(numL - currL, k));
                total %= 10007;
            } else if (str[i] == 'L') {
                currL++;
            }
        }

        cout << total << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using vi = vector<int>;

// int MOD = 10007;
// vi fact(501, 1);

// void gen_fact() {
//     for (int i = 1; i < fact.size(); i++) {
//         fact[i] = (fact[i-1] % MOD) * (i % MOD);
//     }
// }

// int nCr(int n, int r) {
//     if (n == 0 || r == 0) { return 0; }
//     int ans = (fact[n] % MOD) / (fact[r] % MOD);
//         ans /= (fact[n-r] % MOD);
    
//     return ans % MOD;
// }

// int solve() {
//     int c, r; cin >> c >> r;
//     // ls before o, ls after o
//     vi ls;

//     int lcount = 0;
//     while (c--) {
//         char curr; cin >> curr;
//         if (curr == 'L') { lcount++; }
//         else if (curr == 'O') {
//             ls.push_back(lcount);
//             lcount = 0;
//         }
//         cout << curr << " uhh " << c << endl;
//     }
//     ls.push_back(lcount);

//     bool complete = false;
//     int left = 0;
//     int right = 0;
//     int sum = 0;
//     for (int count : ls) {
//         if (!complete) {
//             left = nCr(count, r);
//             if (left > 0) { complete = true; }
//         } else {
//             right = nCr(count, r);
//             if (right == 0) { complete = false; continue; }

//         }
        
//     }
//     return sum;
// }

// int main() {
//     gen_fact();

//     int t; cin >> t;
//     while (t--) { cout << solve() << endl; }
// }