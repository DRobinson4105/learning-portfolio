#include <iostream>

using namespace std;

int main() {
    bool first = false;
    bool second = false;
    int num;
    for (int i = 0; i < 10; i++) {
        cin >> num;
        if (num == 17)
            first = true;
        else if (num == 18)
            second = true;
    }

    if (first && second)
        cout << "both" << endl;
    else if (first)
        cout << 17 << endl;
    else if (second)
        cout << 18 << endl;
    else
        cout << "none" << endl;

    return 0;
}