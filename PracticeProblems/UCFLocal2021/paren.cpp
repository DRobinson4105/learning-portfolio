#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int len = s.size();

    int total = 0;
    int curr = 1;

    for (char c : s) {
        if (c == ' ') continue;

        if (c == ')') {
            total += curr;
            curr++;
        }
        else
            curr = 1;
    }

    cout << total << endl;
    return 0;
}