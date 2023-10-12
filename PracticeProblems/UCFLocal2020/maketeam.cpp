#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int best = INT_MAX;

void solve(vector<vector<int>> videos, int curr, int len, vector<int> res) {
    if (curr == len) {
        int highest = 0;
        for (int time : res)
            highest = max(highest, time);

        best = min(best, highest + 1);
        return;
    }

    for (int time : videos[curr]) {
        int flag = false;

        for (int i = 0; i < curr; i++)
            if (res[i] == time)
                flag = true;
    
        if (flag) continue;

        res[curr] = time;

        solve(videos, curr + 1, len, res);
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> videos(n);
    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        vector<int> times(t);

        for (int j = 0; j < t; j++)
            cin >> times[j];

        videos[i] = times;
    }

    solve(videos, 0, n, res);
    
    cout << best << endl;
    return 0;
}