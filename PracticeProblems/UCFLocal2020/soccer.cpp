#include <iostream>

using namespace std;

int main() {
    int g, p;
    cin >> g >> p;
    int w = p / 3, t = 0, l = 0;

    while (w + t <= g) {
        t = p - w * 3;
        l = g - w - t;
        if (w <= 0 || l < 0) break;
        cout << w << "-" << t << "-" << l << endl;
        w--;
    }

    if (g >= p) {
        w = 0;
        t = p;
        l = g - p;
        cout << w << "-" << t << "-" << l << endl;
    }

    return 0;
}