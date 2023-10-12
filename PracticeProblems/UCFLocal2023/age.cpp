#include <iostream>

using namespace std;

int main() {
    int oAge, aAge, kAge;
    cin >> oAge >> aAge >> kAge;

    for (int a = 0; a * aAge < 150; a++) {
        for (int k = 0; a * aAge + k * kAge <= 150; k++) {
            if (a * aAge + k * kAge == oAge && a > 0 && k > 0) {
                cout << 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}