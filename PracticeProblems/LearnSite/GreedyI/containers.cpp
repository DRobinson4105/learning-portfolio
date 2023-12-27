#include <bits/stdc++.h>

using namespace std;

bool testStacks(string s, int numStacks) {
    priority_queue<char, vector<char>, greater<char>> pq;
    stack<char> temp;
    for (int i = 0; i < numStacks; i++)
        pq.push('Z' + 1);

    for (char c : s) {
        while (!pq.empty()) {
            char top = pq.top(); pq.pop();
            if (c <= top || top == 'Z' + 1) {
                pq.push(c);
                while (!temp.empty()) {
                    pq.push(temp.top()); temp.pop();
                }
                break;
            }
            temp.push(top);
        }
        
        if (pq.empty())
            return false;
    }

    return true;
}

int main() {
    string s; cin >> s;

    for (int t = 1; s.compare("end"); t++) {
        int n;
        for (n = 26; n > 0 && testStacks(s, n); n--) {}

        cout << "Case " << t << ": " << (n + 1) << endl;
        cin >> s;
    }
}