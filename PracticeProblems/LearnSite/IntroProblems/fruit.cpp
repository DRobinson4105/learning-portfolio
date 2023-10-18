#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int stand = 0; stand < n; stand++) {
        int d;
        cin >> d;

        int days[d];

        int neededCost = 0;
        int totalSold = 0;
        int mostLeftover = 0;

        for (int i = 0; i < d; i++) {
            cin >> days[i];

            totalSold += days[i];
            neededCost = max(neededCost, (int)ceil((double)totalSold / (i + 1)));
        }

        totalSold = 0;

        for (int i = 0; i < d; i++) {
            totalSold += days[i];
            mostLeftover = max(mostLeftover, neededCost * (i + 1) - totalSold);
        }

        cout << neededCost << " " << mostLeftover << endl;
    }

    return 0;
}