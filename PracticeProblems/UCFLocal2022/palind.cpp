#include <vector>
#include <iostream>

using namespace std;

bool checkPair(vector<pair<char, char> > pairs, char c1, char c2) {
    if (c1 == c2) return true;

    int size = pairs.size();
    
    for (int i = 0; i < size; i++) {
        if ((pairs[i].first == c1 && pairs[i].second == c2) ||
            (pairs[i].first == c2 && pairs[i].second == c1))
            return true;
    }

    return false;
}

int main() {
    int p, q;
    cin >> p;
    vector<pair<char, char> > pairs(p);

    for (int i = 0; i < p; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        string word;
        cin >> word;
        int len = word.size();

        int flag = 1;

        for (int j = 0; j < len / 2; j++) {
            if (!checkPair(pairs, word[j], word[len - j - 1])) {
                flag = 0;
                break;
            }
        }

        cout << ((flag) ? "YES" : "NO") << endl;
    }

    return 0;
}