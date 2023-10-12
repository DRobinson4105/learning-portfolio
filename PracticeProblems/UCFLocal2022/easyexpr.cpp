#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    if (num1 >= num2 && num1 >= num3) {
        if (num2 + num3 == num1)
            cout << 1 << endl;
        else if (num2 * num3 == num1)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    else if (num2 >= num1 && num2 >= num3) {
        if (num1 + num3 == num2)
            cout << 1 << endl;
        else if (num1 * num3 == num2)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    else {
        if (num2 + num1 == num3)
            cout << 1 << endl;
        else if (num2 * num1 == num3)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    
    return 0;
}