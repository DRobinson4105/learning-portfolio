#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int year = 0; year < n; year++) {
        int e;
        cin >> e;

        int total = 0;

        for (int exam = 0; exam < e; exam++) {
            int s, p;
            cin >> s >> p;

            total += s * ceil(p / 4.0);
        }

        cout << total << endl;
    }
    
    return 0;
}