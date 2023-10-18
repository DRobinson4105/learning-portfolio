#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed;
    cout << setprecision(2);

    int n;
    cin >> n;

    for (int trip = 0; trip < n; trip++) {
        double a, c, tA, tC;
        cin >> a >> c >> tA >> tC;

        cout << a * tA + c * tC << endl;
    }
    return 0;
}