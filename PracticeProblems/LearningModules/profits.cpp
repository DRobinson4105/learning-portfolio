#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N) {
        vector<int> profits(N + 1);
        profits[0] = 0;
        for (int i = 1; i <= N; i++) {
            cin >> profits[i];
            profits[i] += profits[i - 1];
        }

        int highest = INT_MIN;
        for (int i = 0; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (profits[j] - profits[i] > highest)
                    highest = profits[j] - profits[i];
            }
        }

        cout << highest << endl;
        cin >> N;
    }
    return 0;
}