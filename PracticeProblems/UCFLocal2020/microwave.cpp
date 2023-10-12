#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<int, int> bestInput;
int numJumps = INT_MAX;

pair<int, int> correctTime(int seconds) {
    return make_pair(seconds / 60, seconds % 60);
}

int getNumJumps(pair<int, int> time) {
    int jumps = 0;

    if (time.first > 9 && time.first / 10 != time.first % 10)
        jumps++;
    if (time.first % 10 != time.second / 10)
        jumps++;
    if (time.second / 10 != time.second % 10)
        jumps++;

    return jumps;
}

int main() {
    string time;
    int percent;

    cin >> time >> percent;

    int minutes = (int)(time[0] - '0') * 10 + (int)(time[1] - '0');
    int seconds = (int)(time[3] - '0') * 10 + (int)(time[4] - '0');

    int timeSec = minutes * 60 + seconds;

    int low = timeSec - (timeSec * percent / 100);
    int high = timeSec + (timeSec * percent / 100);

    for (int i = low; i <= high; i++) {
        pair<int, int> curr = correctTime(i);

        int jumps = getNumJumps(curr);

        if (jumps < numJumps) {
            numJumps = jumps;
            bestInput = curr;
        }

        if (curr.second < 40 && curr.first > 0) {
            int jumps = getNumJumps(make_pair(curr.first - 1, curr.second + 60));

            if (jumps < numJumps) {
                numJumps = jumps;
                bestInput = make_pair(curr.first - 1, curr.second + 60);
            }
        }
    }
    if (bestInput.first != 0)
        cout << bestInput.first;
    cout << bestInput.second << endl;

    return 0;
}