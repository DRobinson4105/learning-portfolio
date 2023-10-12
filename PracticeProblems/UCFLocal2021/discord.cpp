#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int c, b;
    cin >> c >> b;

    vector<int> listening(b);
    vector<vector<int>> tracker(c);
    vector<set<int>> sending(c);
    for (int i = 0; i < c; i++) {
        tracker[i].resize(c);
    }
    
    int numSending;
    for (int i = 0; i < b; i++) {
        cin >> listening[i];
        listening[i]--;
        cin >> numSending;

        for (int j = 0; j < numSending; j++) {
            int channel;
            cin >> channel;
            sending[listening[i]].insert(channel - 1);
        }
    }

    for (int i = 0; i < c; i++) {
        queue<int> q;
        for (int num : sending[i]) {
            q.push(num);
        }
        
        while (!q.empty()) {
            int channel = q.front();
            q.pop();

            if (tracker[i][channel]) continue;

            tracker[i][channel] = 1;

            for (int num : sending[channel])
                q.push(num);
        }

        tracker[i][listening[i]] = 1;
    }

    int count = 0;
    for (int i = 0; i < b; i++) {
        if (find(tracker[i].begin(), tracker[i].end(), 0) == tracker[i].end()) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}