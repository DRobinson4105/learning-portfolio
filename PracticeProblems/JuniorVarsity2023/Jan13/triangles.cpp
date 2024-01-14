#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> first(3), second(3);

    for (int i = 0; i < 3; i++) cin >> first[i];
    for (int i = 0; i < 3; i++) cin >> second[i];

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    for (int i = 0; i < 3; i++) {
        if (first[i] != second[i]) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (pow(first[0], 2) + pow(first[1], 2) == pow(first[2], 2))
        cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}