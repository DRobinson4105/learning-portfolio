#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    int total = 0;
    int n, k; cin >> n >> k;
    int lowest = 2, highest = k - 1;
    for (int i = 0; i < n; i++) {
        int floor; cin >> floor;
        string res; cin >> res;

        if (res.compare("SAFE")) highest = min(highest, floor - 1);
        else lowest = max(lowest, floor + 1); 
    }

    cout << lowest << " " << highest << endl;
    return 0;
}