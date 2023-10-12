#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double pi =  3.14159265358979;
int s, r;

double part(double x) {
    return (asin(x/r) + 0.5 * sin(2 * asin(x/r)));
}

int main() {
    cin >> s >> r;
    cout << fixed;
    cout << setprecision(2);
    
    if (s / 2 * sqrt(2) <= r) {
        cout << s * s << endl;
    }
    else if (s / 2 >= r) {
        cout << r * r * pi << endl;
    }
    else {
        double num = sqrt(pow(r, 2) - (pow(s, 2) / 4));

        cout << (pow(s, 2) - ((s / 2 - num) * 4 * s / 2) + 
                (4 * pow(r, 2) / 2 * (part(s / 2) - part(num)))) << endl;
    }
    return 0;
}