#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> l1(26);
    vector<int> l2(26);

    for (int i = 1; s1 != "END" || s2 != "END"; i++) {
        for (int i = 0; i < 26; i++) {
            l1[i] = 0;
            l2[i] = 0;
        }

        int len1 = s1.size();
        int len2 = s2.size();
        bool flag = true;

        if (len1 != len2) {
            flag = false;
        }

        for (int i = 0; i < len1 && flag; i++) {
            l1[s1[i] - 'a']++;
            l2[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26 && flag; i++) {
            if (l1[i] != l2[i]) {
                flag = false;
            }
        }
        
        if (flag) {
            cout << "Case " << i << ": same" << endl;
        } else {
            cout << "Case " << i << ": different" << endl;
        }

        cin >> s1 >> s2;
    }
}