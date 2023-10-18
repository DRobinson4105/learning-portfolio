#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int a = 0; a < n; a++) {
        string word;
        cin >> word;

        int curr = 0;
        bool flag = true;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] <= curr) {
                flag = false;
                break;
            }

            curr = word[i];
        }

        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}