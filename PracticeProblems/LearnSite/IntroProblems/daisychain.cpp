#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int c;
    cin >> c;

    for (int inp = 0; inp < c; inp++) {
        long long int n, p, g;
        cin >> n >> p >> g;
        
        long long int res = n * (p - 1) + ceil((double)n / g);
        cout << res << endl;
    }

    return 0;
}