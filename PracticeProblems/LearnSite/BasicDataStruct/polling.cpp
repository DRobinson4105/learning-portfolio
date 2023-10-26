#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> votes;
    vector<string> highest;
    int highestCount = 0;

    for (int i = 0; i < n; i++) {
        string candidate;
        cin >> candidate;

        if (votes.find(candidate) == votes.end())
            votes[candidate] = 1;
        else
            votes[candidate]++;
        
        if (votes[candidate] > highestCount) {
            highest.clear();
            highestCount = votes[candidate];
        }

        if (votes[candidate] == highestCount)
            highest.push_back(candidate);
    }

    sort(highest.begin(), highest.end());

    for (string candidate : highest) {
        cout << candidate << endl;
    }
    return 0;
}