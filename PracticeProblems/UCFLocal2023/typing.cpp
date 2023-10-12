#include <iostream>
#include <string>

using namespace std;
#define COL_LIMIT 9
#define ROW_LIMIT 3

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int res = 1;
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 != len2) {
        cout << 3 << endl;
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        int x1 = (s1[i] - 'a') / 9;
        int y1 = (s1[i] - 'a') % 9;
        int x2 = (s2[i] - 'a') / 9;
        int y2 = (s2[i] - 'a') % 9;

        if (abs(x2 - x1) > 1 || abs(y2 - y1) > 1) {
            cout << 3 << endl;
            return 0;
        }

        if (abs(x2 - x1) == 1 || abs(y2 - y1) == 1)
            res = 2;
    }

    cout << res << endl;

    return 0;
}