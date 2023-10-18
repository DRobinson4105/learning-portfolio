#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int trip = 0; trip < n; trip++) {
        int m;
        double d;
        cin >> m >> d;

        double distance = 0;

        for (int i = 0; i < m; i++) {
            double s;
            cin >> s;

            distance += d / s;
        }

        cout << fixed;
        cout.precision(2);
        cout << distance << endl;
        cout.unsetf(ios::showbase);
    }

    return 0;
}