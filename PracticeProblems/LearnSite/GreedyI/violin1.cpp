#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    for (int s = 0; s < n; s++) {
        int k; cin >> k;
        int total = 0;
        vector<bool> fingers(5, false); fingers[0] = true;

        for (int a = 0; a < k; a++) {
            int note; cin >> note;
            for (int i = note + 1; i < 5; i++) {
                if (fingers[i])
                    total++;
                fingers[i] = false;
            }
            if (!fingers[note])
                total++;
            fingers[note] = true;
        }

        cout << total << endl;
    }
    return 0;
}