#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll fact[17] = {
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800,
    479001600,
    6227020800,
    87178291200,
    1307674368000,
    20922789888000
};

int main() {
    string str; cin >> str;
    ll K; cin >> K;

    while (K) {
        string result = "";
        int length = str.length();
        map<char, int> freq;

        for (char c : str) {
            if (freq.find(c) == freq.end())
                freq[c] = 0;
            freq[c] += 1;
        }

        while (freq.size()) {
            ll totalPerm = fact[length];

            for (pii p : freq)
                totalPerm /= fact[p.second];

            for (pii p : freq) {
                ll charPerm = totalPerm * p.second / length;

                if (K > charPerm)
                    K -= charPerm;
                else {
                    result += p.first;
                    freq[p.first]--;
                    if (!freq[p.first])
                        freq.erase(p.first);
                    break;
                }
            }

            length--;
        }

        cout << result << endl;
        cin >> str;
        cin >> K;
    }
}