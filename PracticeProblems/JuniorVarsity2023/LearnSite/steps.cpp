#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int distances[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> distances[i][j];

    int t;
    cin >> t;

    for (int w = 0; w < t; w++) {
        string walk;
        cin >> walk;

        int len = walk.size();

        int total = 0;

        for (int i = 1; i < len; i++)
            total += distances[walk[i - 1] - 'A'][walk[i] - 'A'];

        cout << total << endl;
    }
    
    return 0;
}