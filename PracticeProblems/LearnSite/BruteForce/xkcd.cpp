#include <bits/stdc++.h>

using namespace std;

vector<string> result;

bool valid(int i) {
    return i != 0 && i != 4 && i != 8 && i != 14 && i != 20 && i != 24;
}

void permute(string str, int curr, int last, int length, bool first) {
    if (curr == 42 && str.length() == length) {
        reverse(str.begin(), str.end());
        result.push_back(str);
        return;
    }

    if (curr >= 42 || str.length() >= length)
        return;

    int highest = min(26, 42 - curr);
    if (first) {
        highest = min(highest, last);
        for (int i = 1; i < highest; i++) {
            if (valid(i)) permute(str + ((char)(i + 'a')), curr + i + 1, last, length, false);
        }
    } else {
        for (int i = last + 1; i < highest; i++) {
            if (valid(i)) permute(str + ((char)(i + 'a')), curr + i + 1, i, length, false);
        }
    }


}

int main() {
    int n;
    cin >> n;

    while (n != 42) {
        cout << "XKCD-like name(s) of length: " << n << endl;
        for (int i = 1; i < 26; i++) {
            if (valid(i)) permute(string(1, (char)(i + 'a')), i + 1, i, n, true);
        }
        if (result.size()) {
            sort(result.begin(), result.end());
            for (string str : result)
                cout << str << endl;
        } else {
            cout << "Mostly Harmless" << endl;
        }

        cin >> n;
        result.clear();
    }

    cout << "The answer to life, the universe and everything!" << endl;
    return 0;
}