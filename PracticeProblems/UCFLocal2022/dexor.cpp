#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int num1, num2;
    string res = "";
    cin >> num1 >> num2;

    while (num1 || num2) {
        if ((num1 % 10 <= 2 && num2 % 10 <= 2) || (num1 % 10 >= 7 && num2 % 10 >= 7))
            res += '0';
        else
            res += '9';  
        num1 /= 10;
        num2 /= 10; 
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}