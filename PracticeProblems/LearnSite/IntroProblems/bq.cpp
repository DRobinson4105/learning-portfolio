#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;

int set(int mask, int pos) {
    return mask | (1 << pos);
}

int reset(int mask, int pos) {
    return on(mask, pos) ? mask ^ (1 << pos) : mask;
}

int main() {
    int c;
    cin >> c;

    for (int inp = 0; inp < c; inp++) {
        int n, s;
        cin >> n >> s;

        unordered_map<string, int> bits;
        string people[n];
        string order[s];
        int mask = 0;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;

            people[i] = str;
            bits[str] = i;
            mask = set(mask, i);
        }

        for (int sec = 0; sec < s; sec++)
            cin >> order[sec];

        for (int sec = 0; sec < s; sec++) {
            mask = reset(mask, bits[order[sec]]);

            if (log2(mask) == trunc(log2(mask))) {
                cout << people[(int)log2(mask)] << " " << sec + 1 << endl;
                break;
            }
        }
    }

    return 0;
}