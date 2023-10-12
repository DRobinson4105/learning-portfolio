#include <iostream>

using namespace std;

int numOfDigit(int num, int digit) {
    int count = 0;

    while (num > 0) {
        if (num % 10 == digit)
            count++;
        
        num /= 10;
    }

    return count;
}

int main() {
    int lower, upper, digit;
    cin >> lower >> upper >> digit;

    int total = 0;

    for (int num = lower; num <= upper; num++) {
        total += numOfDigit(num, digit);
    }

    cout << total << endl;

    return 0;
}