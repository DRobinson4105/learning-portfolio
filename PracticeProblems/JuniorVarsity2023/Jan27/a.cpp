#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    unordered_map<int, int> mp;

    int n, k, c; cin >> n >> k >> c;

    vector<int> res;
    vector<pii> scores(n);
    vector<bool> used(n);
    vector<bool> overflow(n);
    int curr = 0;
    for (int i = 0; i < n; i++) {
        int t, s; cin >> t >> s;
        scores[i] = {t,s};
        if (mp.find(s) == mp.end())
            mp[s] = 0;

        if (curr < k) {
            if (mp[s] >= c)
                overflow[i] = true;
            else
                curr++;
            used[i] = true;

            mp[s]++;
        }
    }


    int diff = k - curr;

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            if (overflow[i] && diff) {
                cout << scores[i].first << endl;
                diff--;
            } else if (!overflow[i]) {
                cout << scores[i].first << endl;
            }
        }
    }
    return 0;
}