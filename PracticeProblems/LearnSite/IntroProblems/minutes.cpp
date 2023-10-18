#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int time = 0; time < n; time++) {
        int d, h, m;
        cin >> d >> h >> m;

        cout << d * 24 * 60 + h * 60 + m << endl;
    }
    
    return 0;
}