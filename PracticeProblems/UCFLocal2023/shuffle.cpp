#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void shuffle(string& s1, string& s2, int len) {
    char* result = (char*) malloc(sizeof(char) * len * 2);
    for (int i = 0; i < len; i++) {
        result[i * 2] = s1[i];
        result[i * 2 + 1] = s2[i];
    }

    for (int i = 0; i < len; i++) {
        s1[i] = result[i + len];
        s2[i] = result[i];
    }

    free(result);
}

int main() {
    int n;
    cin >> n;

    for (int a = 1; a <= n; a++) {
        int c;
        string s1, s2, target;
        cin >> c;
        cin >> s1 >> s2 >> target;
        cout << a << " ";

        vector<string> used;
        int count = 0;

        while (true) {
            string result = s1.substr(0, c) + s2.substr(0, c);
            cout << result << endl;

            if (find(used.begin(), used.end(), result) != used.end()) {
                cout << -1 << endl;
                break;
            }

            if (result == target) {
                cout << count << endl;
                break;
            }

            used.push_back(result);
            shuffle(s1, s2, c);
            count++;
        }
    }
    return 0;
}