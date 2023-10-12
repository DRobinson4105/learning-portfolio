#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int w = 8;
    double x = 2;
    double y = -6;
    cout << ceil((abs(atan(x / y)) + M_PI + M_PI_2) / (M_PI * 2) * w) << endl;
    return 0;
}