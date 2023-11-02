#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        int sA = floor(sqrt(a));
        int sB = floor(sqrt(b));

        int res = b - a + 1 - (sB - sA);
        if (pow(sA, 2) == a) res--;

        cout << res << endl;
    }

    return 0;
}