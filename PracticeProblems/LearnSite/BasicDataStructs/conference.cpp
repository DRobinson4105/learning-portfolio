#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct result {
    string name;
    int room, time;

    result(string n, int r, int t) : name(n), room(r), time(t) {}
};


class Compare {
    public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first > b.first;

        return a.second > b.second;
    }
};

bool compute(vector<pair<string, int>> lectures, vector<result*>& results, int n, int t, int k) {
    results.clear();
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    for (int i = 0; i < k; i++) {
        results.push_back(new result(lectures[i].first, i, 0));
        pq.push(make_pair(i, lectures[i].second));
    }

    for (int i = k; i < n; i++) {
        // cout << "3" << endl;
        pair<int, int> front = pq.top();

        if (t - front.second < lectures[i].second)
            return false;

        pq.pop();
        pq.push(make_pair(front.first, front.second + lectures[i].second));
        results.push_back(new result(lectures[i].first, front.first, front.second));
    }

    sort(results.begin(), results.end(), [](result* a, result* b) {
        return a->name.compare(b->name) < 0;
    });

    return true;
}

int main() {
    int n, t, k, totalTime = 0;
    cin >> n >> t;

    vector<pair<string, int>> lectures(n);
    vector<result*> results;

    for (int i = 0; i < n; i++) {
        cin >> lectures[i].first >> lectures[i].second;
        totalTime += lectures[i].second;
    }

    int min = ceil((double)totalTime / t);
    int max = n;

    // cout << compute(lectures, results, n, t, 3) << endl; // debug

    while (max - min > 1) {
        results.clear();
        int k = (max + min) / 2;
        // cout << k << endl; // debug
        // cout << min << " " << max << endl; // debug
        if (compute(lectures, results, n, t, k))
            max = k;
        else
            min = k;
        // cout << min << " " << max << endl; // debug
    }
    if (compute(lectures, results, n, t, min)) {
        cout << min << endl;
    } else {
        compute(lectures, results, n, t, max);
        cout << max << endl;
    }

    for (result* res : results) {
        cout << res->name << " " << res->room << " " << res->time << endl;
    }

    return 0;
}