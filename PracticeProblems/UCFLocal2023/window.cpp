#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int len, sub;
    cin >> len >> sub;
    int newLen = len - sub + 1;

    vector<vector<int>> windows(newLen, vector<int>(sub + 2));

    windows[0][0] = 1;
    for (int i = 0; i < sub; i++) {
        int num;
        cin >> num;
        windows[0][1] += (num * (i + 1));
        windows[0][i + 2] = num;
    }

    for (int i = 1; i < newLen; i++) {
        windows[i][0] = i + 1;
        int num;
        cin >> num;

        for (int j = 3; j < sub + 2; j++) {
            windows[i][1] += (windows[i - 1][j] * (j - 2));
            windows[i][j - 1] = windows[i - 1][j];
        }

        windows[i][1] += (num * sub);
        windows[i][sub + 1] = num;
    }

    // for (int i = 0; i < windows.size(); i++) {
    //     for (int j = 0; j < windows[i].size(); j++) {
    //         cout << windows[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    sort(windows.begin(), windows.end(), [](vector<int> left, vector<int> right) {
        return left[1] < right[1];
    });

    for (int i = 0; i < windows.size(); i++) {
        cout << windows[i][0] << " " << windows[i][1] << endl;
    }
    return 0;
}

// && (i - j) <= (len - sub)