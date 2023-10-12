#include <iostream>

using namespace std;

int weight(int num) {
    int sumDigits = 0;
    int numDigits = 0;
    while (num > 0) {
        sumDigits += num % 10;
        numDigits++;
        num /= 10;
    }

    return sumDigits * numDigits;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    int weight1 = weight(num1);
    int weight2 = weight(num2);

    if (weight1 > weight2)
        cout << 1 << endl;
    else if (weight2 > weight1)
        cout << 2 << endl;
    else
        cout << 0 << endl;

    return 0;
}