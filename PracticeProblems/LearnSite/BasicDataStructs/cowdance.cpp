#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

class Compare {
    public:
        bool operator() (int a, int b) {
        return a > b;
    }
};

bool compute(vector<int> cows, int n, int t, int k) {
    priority_queue<int, vector<int>, Compare> pq;

    for (int i = 0; i < k; i++) {
        pq.push(cows[i]);
    }

    for (int i = k; i < n; i++) {
        int val = pq.top(); pq.pop();

        if (val + cows[i] > t) return false;

        pq.push(val + cows[i]);
    }

    return true;
}

int main() {
    int n, t; cin >> n >> t;
    double total = 0;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        total += cows[i];
    }

    int min = ceil(total / t);
    int max = n;

    while (max - min > 1) {
        int k = (max + min) / 2;
        if (compute(cows, n, t, k))
            max = k;
        else
            min = k;
    }

    if (compute(cows, n, t, min))
        cout << min << endl;
    else
        cout << max << endl;

    return 0;
}