#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int n;
    cin >> n;

    vi denominations(n);

    for (int i = 0; i < n; i++)
        cin >> denominations[i];

    bool flag = true;
    for (int i = 1; i < n && flag; i++) {
        if (denominations[i] < denominations[i - 1] * 2) {
            cout <<  << endl;
            flag = false;
        }
    }

    cout << (flag ? "can")
    return 0;
}