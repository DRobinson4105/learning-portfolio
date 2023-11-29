#include <bits/stdc++.h>
using namespace std;

bool foundAny;

void permute(string str, int curr) {
    if (curr == 42) {
        foundAny = true;
        cout << str << endl;
        return;
    }

    if (curr > 42)
        return;

    int highest = min(25, 41 - curr);

    for (int i = 0; i <= highest; i++) {
        permute(str + ((char)i))
    }
}

int main() {
    int n; cin >> n;

    while (n != 42) {
        
    }
    return 0;
}