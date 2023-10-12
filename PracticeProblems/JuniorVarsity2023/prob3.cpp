#include <iostream>

using namespace std;

int compute(vector<int> count, int size) {
    long long int result = 0;
    for (int i = 0; i < size; i++) {
        if (count[i] == 2) continue;

        int curr = 0;
        vector<int> stored;

        for (int j = size; j < size * 2 && curr < 2; j++) {
            if (count[j] != 2) {
                count[j]++;
                curr++;
            }
        }

        if (curr < 2) return 0;

        count[i]++;
        compute(count, size);
        count[i]
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        if (n == 1) 
    }
    return 0;
}