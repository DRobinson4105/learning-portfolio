#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int total = 0;

    while (n >= 10) {
        int curr = 1;
        while (n) {
            curr *= n % 10;
            n /= 10;
        }
        n = curr;
        total++;
    }

    cout << total << endl;
    return 0;
}