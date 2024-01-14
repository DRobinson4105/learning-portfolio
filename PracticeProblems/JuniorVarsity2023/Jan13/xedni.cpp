#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        names[i] = s;
    }

    sort(names.begin(), names.end());
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }
    return 0;
}