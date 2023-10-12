#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    long long int count = 0;
    cin >> n >> k;
    int total = pow(2, n);
    vector<int> players(total);
    for (int i = 0; i < total; i++) {
        cin >> players[i];
    }

    sort(players.begin(), players.end());
    reverse(players.begin(), players.end());

    for (int i = 0; i < players.size(); i++) {
        cout << players[i] << " ";
    }

    cout << endl;

    vector<int> winners;
    winners.push_back(players[0]);
    int len = 1;

    for (int a = 0; a < n; a++) {
        vector<int> next(len);
        for (int i = 0; i < len; i++) {
            next[i] = players[i + len];
        }

        int i = 0;
        int j = 0;
        while (i < len && j < len) {
            if (winners[i] + k > next[j])
                i++;
            else if (winners[i] - k < next[j])
                j++;
            else {
                count++;
                i++;
                j++;
            }
        }
    for (int i = 0; i < winners.size(); i++) {
        cout << winners[i] << " ";
    }
    cout << endl << count << endl;


        winners.insert(winners.end(), next.begin(), next.end());
        len *= 2;
    }

    cout << count << endl;
    return 0;
}