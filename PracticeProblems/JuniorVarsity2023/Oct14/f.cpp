#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<vector<int> > days(n, vector<int>(3));
    vector<int> clean(n);
    vector<int> visitingDays(d);

    for (int i = 0; i < n; i++) {
        days[i][0] = i + 1;
        cin >> days[i][1] >> days[i][2];

        clean[i] = days[i][2] - days[i][1];
        if (i != 0)
            clean[i] += clean[i - 1];
    }

    for (int i = 0; i < d; i++) {
        cin >> visitingDays[i];
        visitingDays[i]--;
    }

    int numCleaningDays = visitingDays[visitingDays.size() - 1] + 1;

    int lastDay = 0;
    int diff = 0;
    for (int day : visitingDays) {
        int extraClean = 0;

        for (int i = lastDay; i <= day; i++)
            extraClean += days[i][2] - days[i][1];

        sort(days.begin() + lastDay, days.begin() + day + 1);

        for (int i = lastDay; i <= day; i++) {
            if (days[i][2] > extraClean) break;
            
            extraClean -= days[i][2];
            numCleaningDays--;
        }

        diff += extraClean - clean[day];
        lastDay = day + 1;
    }

    cout << numCleaningDays << endl;
    return 0;
}