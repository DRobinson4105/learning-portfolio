#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> vi;

string encrypt(string str) {
    int n = str.size();
    vi values(n);
    string result = "";

    for (int i = 0; i < n; i++) {
        // cout << str[i] << endl;
        values[i] = ((str[i] == ' ') ? 0 : ((str[i] - 'a') % 26 + 1));
    }

    for (int i = 1; i < n; i++) {
        values[i] += values[i - 1];
    }

    for (int i = 0; i < n; i++) {
        values[i] %= 27;
    }

    for (int i = 0; i < n; i++) {
        result += values[i] == 0 ? ' ' : ((char)(values[i] - 1 + 'a'));
    }

    return result;
}

string decrypt(string str) {
    int n = str.size();
    vi values(n);
    int currSub = 0;
    string result = "";

    for (int i = 0; i < n; i++) {
        values[i] = ((str[i] == ' ') ? 0 : ((str[i] - 'a') % 26 + 1));
    }

    for (int i = n - 1; i > 0; i--) {
        values[i] = values[i] - values[i - 1];
        if (values[i] < 0) values[i] += 27;
    }


    for (int i = 0; i < n; i++) {
        result += values[i] == 0 ? ' ' : ((char)(values[i] - 1 + 'a'));
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    for (int msg = 0; msg < n; msg++) {
        string str;
        char op, garb;
        cin >> op;
        getline(cin, str);
        str = str.substr(1, str.length() - 1);

        if (op == 'e') {
            cout << encrypt(str) << endl;
        } else {
            cout << decrypt(str) << endl;
        }
    }
    
    return 0;
}