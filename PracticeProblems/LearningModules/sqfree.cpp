#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << (b - a - ceil(sqrt(b) - sqrt(a)) + 1) << endl;
    }
    return 0;
}