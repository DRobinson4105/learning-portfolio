#include <iostream>

using namespace std;

bool isPalindrome(int num) {
    char tmp[14];
    int len = 0;
    while (num > 0) {
        tmp[len] = num % 10;
        len++;
        num /= 10;
    }

    for (int i = 0; i < len; i++)
        if (tmp[i] != tmp[len - i - 1])
            return false;

    return true;
}

bool isPrime(int num) {
    for (int i = 2; i < num; i++)
        if (num % i == 0) return false;
    
    return true;
}

int main() {
    int L, H;
    cin >> L >> H;
    
    int count = 0;

    for (int i = L; i <= H; i++)
        if (isPalindrome(i) && isPrime(i))
            count++;

    cout << count << endl;

    return 0;
}