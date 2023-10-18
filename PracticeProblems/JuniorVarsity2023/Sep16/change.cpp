#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int z = 1; z <= n; z++) {
        int c;
        cin >> c;

        vector<int> packages(c);

        for (int i = 0; i < c; i++)
            cin >> packages[i];

        sort(packages.begin(), packages.end());

        if (packages[0] != 1) {
            cout << "Set #" << z << ": 1" << endl << endl;
            continue;
        }

        int curr = 1;
        int i = 0;
        while (packages[i] == curr) {
            curr *= 2;
            i++;
        }
            
        int sum = packages[i - 1] * 2 - 1;
        vector<int> stored;
        int highest = sum;
        bool flag = true;

        for (; i < c && flag; i++) {
            if (packages[i] > highest + 1) {
                cout << "Set #" << z << ": " << highest + 1 << endl << endl;
                flag = false;
            } else {
                highest = packages[i] + highest;
            }
        }

        if (flag) {
            cout << "Set #" << z << ": " << highest + 1 << endl << endl;
        }
    }
    return 0;
}