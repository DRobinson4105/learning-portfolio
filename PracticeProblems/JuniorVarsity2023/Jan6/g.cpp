#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, n; cin >> c >> n;
    unordered_set<int> errorLines;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        errorLines.insert(num);
    }

    vector<pair<int, int>> errors;
    vector<pair<int, int>> correct;

    for (int i = 1; i <= c;) {
        if (errorLines.count(i)) {
            int first = i;
            while (i <= c && errorLines.count(i))
                i++;

            errors.push_back({first, i - 1});
        } else {
            int first = i;
            while (i <= c && !errorLines.count(i))
                i++;

            correct.push_back({first, i - 1});
        }
    }

    cout << "Errors: ";
    for (int i = 0; i < errors.size(); i++) {
        cout << (errors[i].first == errors[i].second ? (to_string(errors[i].first) + "") : (to_string(errors[i].first) + "-" + to_string(errors[i].second)));
        if (i == errors.size() - 1)
            cout << endl;
        else if (i == errors.size() - 2)
            cout << " and ";
        else
            cout << ", ";
    }
    cout << "Correct: ";
    for (int i = 0; i < correct.size(); i++) {
        cout << (correct[i].first == correct[i].second ? (to_string(correct[i].first) + "") : (to_string(correct[i].first) + "-" + to_string(correct[i].second)));
        if (i == correct.size() - 1)
            cout << endl;
        else if (i == correct.size() - 2)
            cout << " and ";
        else
            cout << ", ";
    }

    return 0;
}