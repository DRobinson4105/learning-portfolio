#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef priority_queue<ll, vector<ll>, greater<ll>> heap;

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; t++) {
        int n; cin >> n;

        heap pq;
        for (int a = 0; a < n; a++) {
            int num; cin >> num;
            pq.push(num);
        }

        ll total = 0;
        while (pq.size() > 1) {
            ll num1 = pq.top(); pq.pop();
            ll num2 = pq.top(); pq.pop();
            total += num1 + num2;
            pq.push(num1 + num2);
        }

        cout << total << endl;
    }

    return 0;
}