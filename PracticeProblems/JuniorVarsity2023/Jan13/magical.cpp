#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    int curr = 4;
    while ((n - 3) % curr != 0) {
        curr++;
    } 

    cout << curr << endl;
    return 0;
}