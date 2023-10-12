#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double r, s, h, m, d;
    cin >> r >> s >> h >> m >> d;
    cout << fixed;
    cout << setprecision(6);

    double newR = (s - r) / h * d + r;
    double volumeTotal = (1.0 / 3) * M_PI * h * (r * r + r * s + s * s);
    double volumeLeft = (1.0 / 3) * M_PI * d * (r * r + r * newR + newR * newR);

    cout << volumeTotal << " " << volumeLeft << " " << newR << endl;
    double res = m / (volumeTotal - volumeLeft) * volumeLeft;
    cout << res << endl;
    return 0;
}