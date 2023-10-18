#include <iostream>

using namespace std;

int main() {
    int dS, yS, dM, yM;
    cin >> dS >> yS >> dM >> yM;

    dS *= -1;
    dM *= -1;

    dS += yS;
    dM += yM;

    while (dS != dM) {
        while (dS < dM) {
            dS += yS;
        }

        while (dM < dS) {
            dM += yM;
        }
    }

    cout << dS << endl;
    return 0;
}