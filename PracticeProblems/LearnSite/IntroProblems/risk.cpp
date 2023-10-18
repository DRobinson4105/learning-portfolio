#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c;
    cin >> c;

    for (int inp = 0; inp < c; inp++) {
        int n;
        cin >> n;

        vector<int> attackers(n);
        vector<int> defenders(n);

        for (int i = 0; i < n; i++)
            cin >> attackers[i];

        for (int i = 0; i < n; i++)
            cin >> defenders[i];

        sort(attackers.begin(), attackers.end());
        sort(defenders.begin(), defenders.end());

        int i = 0;

        for (int j = 0; j < n; j++) {
            if (defenders[j] >= attackers[i]) {
                i++;
            }
        }

        cout << i << endl;
    }

    return 0;
}