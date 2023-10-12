#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int main() {
    int numVoters;
    cin >> numVoters;

    unordered_map<string, int> votes;
    for (int i = 0; i < numVoters; i++) {
        string tmp;
        cin >> tmp;
        auto it = votes.find(tmp);
        if (it != votes.end())
            (it->second)++;
        else
            votes[tmp] = 0;
    }

    vector<string> res;
    int numCandidates = 0;
    int lowest = INT_MAX;
    for (auto it : votes) {
        if (it.second < lowest) {
            lowest = it.second;
            res.clear();
            numCandidates = 0;
        }
        if (it.second == lowest) {
            res.push_back(it.first);
            numCandidates++;
        }
    }

    cout << numCandidates << endl;

    for (int i = numCandidates - 1; i >= 0; i--) {
        cout << res[i] << endl;
    }

    return 0;
}