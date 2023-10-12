#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string filename;
    string inputFile;
    int r, d, e, c, t;
    cin >> filename;
    cin >> inputFile;
    cin >> r >> d >> e;

    cin >> c;
    vector<string> expected(c);
    for (int i = 0; i < c; i++) cin >> expected[i];

    cin >> t;
    vector<string> submitted(t);
    for (int i = 0; i < t; i++) cin >> submitted[i];

    if (inputFile != filename + ".c" && inputFile != filename + ".cpp" &&
        inputFile != filename + ".java" && inputFile != filename + ".py")
            cout << "Compile Error" << endl;
    else if (r != 0)
        cout << "Run-Time Error" << endl;
    else if (e > d)
        cout << "Time Limit Exceeded" << endl;
    else if (c != t)
        cout << "Wrong Answer" << endl;
    else {
        for (int i = 0; i < c; i++) {
            if (expected[i] != submitted[i]) {
                cout << "Wrong Answer" << endl;
                return 0;
            }
        }

        cout << "Correct" << endl;
    }

    return 0;
}