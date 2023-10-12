#include <iostream>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num > r) count1++;
        else if (num < r) count2++;
    }

    if (count1 == count2)
        cout << 0 << endl;
    else if (count1 < count2)
        cout << 1 << endl;
    else
        cout << 2 << endl;

    return 0;
}