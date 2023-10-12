#include <iostream>

using namespace std;

int main() {
    int first, additonal, total;
    cin >> first >> additonal >> total;
    if (total <= 1000)
        cout << first * total << endl;
    else
        cout << (first * 1000 + additonal * (total - 1000)) << endl;
    return 0;
}