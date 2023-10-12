#include <iostream>
#include <string>

using namespace std;

int main() {
    int c, d, numJumps = 0;
    cin >> c >> d;
    d++;

    string path;
    cin >> path;

    for (int i = 0; i < c;) {
        int jump = i + d;

        if (jump >= c - 1) {
            numJumps++;
            break;
        }

        while (jump > i && path[jump] == 'X')
            jump--;

        if (jump == i) {
            numJumps = 0;
            break;
        }

        numJumps++;
        i = jump;
    }

    cout << numJumps << endl;
    return 0;
}