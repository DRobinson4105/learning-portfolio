#include <iostream>

using namespace std;

int main() {
    int c;
    cin >> c;

    for (int inp = 0; inp < c; inp++) {
        int n, k;
        cin >> n >> k;

        int sequence[n];

        for (int i = 0; i < n; i++)
            cin >> sequence[i];

        for (int q = 0; q < k; q++) {
            for (int i = 0; i < n - 1; i++)
                sequence[i] += sequence[i + 1];

            n--;
        }

        for (int i = 0; i < n; i++)
            cout << sequence[i] << " ";

        cout << endl;
    }

    return 0;
}