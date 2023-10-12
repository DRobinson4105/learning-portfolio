#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int flag = 1;
        for (int i = 2; i < num; i++) {
            if (num % i == 0)
                flag = 0;
        }

        cout << flag << endl;
    }
    return 0;
}