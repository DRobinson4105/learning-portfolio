#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main() {
    double f, k;
    cin >> f >> k;

    int res = round(k / f);

    if (res % 2 == 0)
        cout << "up" << endl;
    else
        cout << "down" << endl;
    return 0;
}