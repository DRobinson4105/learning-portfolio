#include <iostream>
#include <string>

using namespace std;

int main() {
    string one, two;
    int letters1[26];
    int letters2[26];
    int num = 1;

    cin >> one >> two;

    while (one.compare("END") != 0 || two.compare("END") != 0) {
        for (int i = 0; i < 26; i++) {
            letters1[i] = 0;
            letters2[i] = 0;
        }

        int len1 = one.size();
        int len2 = two.size();
        bool same = true;

        if (len1 != len2) {
            same = false;
        } else {
            for (int i = 0; i < len1; i++) {
                letters1[one[i] - 'a']++;
                letters2[two[i] - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                if (letters1[i] != letters2[i]) {
                    same = false;
                    break;
                }
            }
        }

        cout << "Case " << num << ": " << (same ? "same" : "different") << endl;
        num++;
        cin >> one >> two;
    }

    return 0;
}