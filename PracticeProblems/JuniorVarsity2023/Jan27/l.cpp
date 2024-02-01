#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;

    int minimum = 51;
    int maximum = 0;

    for (int i = 1; i < n; i++) {
        int num; cin >> num;

        minimum = min(minimum, num);
        maximum = max(maximum, num);
    }
    if (maximum != b && minimum != a) {
        cout << -1 << endl;
    } else if (maximum != b) {
        cout << b << endl;
    } else if (minimum != a) {
        cout << a << endl;
    } else {
        for (int i = a; i <= b; i++) {
            cout << i << endl;
        }
    }
    return 0;
}