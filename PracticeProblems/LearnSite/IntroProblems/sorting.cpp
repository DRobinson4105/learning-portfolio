#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int c = 1; c <= n; c++) {
        int m;
        cin >> m;

        vector<pair<string, vector<int>>> students(m);

        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;

            int len = s.size();
            vector<int> counts(26, 0);

            for (int j = 0; j < len; j++) {
                counts[s[j] - 'A']++;
            }

            students[i].first = s;
            students[i].second = counts;
        }

        sort(students.begin(), students.end(), [](pair<string, vector<int>> a, pair<string, vector<int>> b){
            for (int i = 0; i < 26; i++) {
                if (a.second[i] != b.second[i])
                    return a.second[i] > b.second[i];
            }
            
            return true;
        });

        cout << "Class #" << c << " ordering" << endl;
        for (int i = 0; i < m; i++)
            cout << students[i].first << endl;

        cout << endl;
    }

    return 0;
}