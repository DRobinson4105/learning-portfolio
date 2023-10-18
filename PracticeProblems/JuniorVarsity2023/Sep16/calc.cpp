#include <iostream>
#include <limits.h>

using namespace std;

int best = INT_MAX;
void solve(int target, int curr, int count) {
    if (count > best || count > 12 || curr > 1000000000) {
        return;
    }
    if (target == curr) {
        best = count;
    }

    solve(target, curr * 3, count + 1);
    solve(target, curr / 2, count + 1);
    solve(target, curr + 1, count + 1);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        int highest = -1;
        for (int num = 1; num < 100; num++) {
            solve(num, k, 0);
            highest = max(highest, best);
            best = INT_MAX;
        }

        cout << highest << endl;
    }
    return 0;
}