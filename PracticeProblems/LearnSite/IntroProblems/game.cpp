#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int inp = 0; inp < n; inp++) {
        string s;
        cin >> s;

        int curr = 0;
        int lowest = 0;

        for (char c : s) {
            if (c == 'v')
                curr++;
            else if (c == '^')
                curr--;

            lowest = max(lowest, curr);
        }

        cout << lowest << endl;
    }
    
    return 0;
}