#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long int total = 0;
    long long int lowest = 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        total += t;
        lowest = min(total, lowest);
    }

    cout << (-lowest) << endl;
    return 0;
}