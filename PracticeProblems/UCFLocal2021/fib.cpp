#include <iostream>

using namespace std;

int main() {
    int target1, target2;
    int num1, num2, tmp;
    cin >> target1 >> target2;

    num1 = target1;
    num2 = target2;

    int count = 2;
    do {
        tmp = (num1 + num2) % 10;
        num1 = num2;
        num2 = tmp;
        count++;
    } while (num1 != target1 || num2 != target2);

    cout << count << endl;
    return 0;
}