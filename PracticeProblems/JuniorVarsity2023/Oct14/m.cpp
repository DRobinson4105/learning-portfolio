#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;

    for (int i = 0; i <= s.length() / 2; i++) {
        if (s[i] == s[s.length() - i - 1])
            continue;
        
        i++;
        if (s[i] == s[s.length() - i - 1]) {
            if (i == s.length() / 2)
                count++;
            else
                count += 2;

            continue;
        }

        double curr = 1;
        while (i < s.length() / 2) {
            if (s[i] == s[s.length() - i - 1])
                break;

            curr++;
            i++;
        }

        count += ceil(curr / 2);
    }

    cout << count << endl;
    return 0;
}