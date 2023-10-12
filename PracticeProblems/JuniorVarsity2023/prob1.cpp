#include <iostream>
#include <math.h>

using namespace std;

int numDigits(int n) {
    if (n == 0) return 0;

    return 1 + numDigits(n / 10);
}

int main() {
    double n, stored;
    cin >> n;
    stored = n;
    while (stored != 0) {
        if (n != (int)n) {
            cout << stored << " is not a powerful number." << endl;
        } else {
            int result = 0;
            int digits = numDigits(n);

            for (int i = digits; i >= 1; i--) {
                result += pow(((int)n % 10), i);
                n /= 10;
            }

            if (result == stored)
                cout << stored << " is a powerful number." << endl;
            else
                cout << stored << " is not a powerful number." << endl;
        }

        cin >> n;
        stored = n;
    }
    return 0;
}