#include <bits/stdc++.h>

using namespace std;

void compute(int curr, int num, int n) {
    if (curr == n) {
        cout << num << endl;
        return;
    }
    curr++;

    for (int i = 0; i <= 9; i++) {
        num *= 10;
        num += i;
        if (num != 0 && num % curr == 0)
            compute(curr, num, n);
        num /= 10;
    }
}

int main() {
    int T; cin >> T;

    for (int test = 0; test < T; test++) {
        int n; cin >> n;

        compute(0, 0, n);
    }
    return 0;
}