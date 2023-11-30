#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, p, x;
    double res;
    cin >> n >> p;
    
    x = n / (p - 1);

    res = double(x * p) / (n + 1);
    for (int i = 2; i <= x; i++)
        res *= double(n - p + i) / (n + i);

    cout << fixed;
    cout << setprecision(7);
    cout << res << endl;
    return 0;
}