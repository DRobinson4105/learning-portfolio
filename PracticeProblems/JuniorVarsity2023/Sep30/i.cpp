#include <iostream>
#include <string>

using namespace std;

int getTetr(char c) {
    switch(c) {
        case 'J': return 0;
        case 'L': return 1;
        case 'S': return 2;
        case 'Z': return 3;
        case 'I': return 4;
        case 'O': return 5;
        case 'T': return 6;
        default: return 7;
    }
}

bool on(int mask, int pos) {
    return (mask & (1 << pos)) > 0;
}

int set(int mask, int pos) {
    return mask | (1 << pos);
}

int result(string s, int size) {
    for (int i = 0; i < size; i += 7) {
        int mask = 0;
        for (int j = 0; j < 7 && (i + j) < size; j++) {
            int tetr = getTetr(s[j + i]);
            if (tetr == 7) continue;
            if (on(mask, tetr))
                return 0;

            mask = set(mask, tetr);
        }
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        string s;
        cin >> s;

        int size = s.size();
        int res = 0;
        for (int i = 0; res == 0 && i < 7; i++) {
            res += result(s, size);
            s = "x" + s;
            size++;
        }
        cout << res << endl;
    }
    return 0;
}