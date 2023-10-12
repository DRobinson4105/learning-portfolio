#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, pair<int, int>> counts;
    
    for (int rank = 1; rank <= n; rank++) {
        string s;
        cin >> s;
        if (counts.find(s) == counts.end())
            counts[s] = make_pair(rank, 1);
        else {
            counts[s].first += rank;
            counts[s].second++;
        }
    }

    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> ranks;
    for (auto it : counts) {
        ranks.push(make_pair((double)it.second.first / it.second.second, it.first));
    }

    while (!ranks.empty()) {
        cout << ranks.top().second << endl;
        ranks.pop();
    }

    return 0;
}