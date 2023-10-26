#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> rankings(n);

    for (int i = 0; i < n; i++) cin >> rankings[i];

    for (int i = 0; i < n;) {
        set<string> s1;
        set<string> s2;
        string s;
        int total = 0;

        do {
            cin >> s;
            if (s.compare(rankings[i]) != 0) {
                set<string>::iterator it1 = s2.find(rankings[i]);
                set<string>::iterator it2 = s1.find(s);
                if (it1 != s2.end()) {
                    s2.erase(it1);
                } else {
                    s1.insert(rankings[i]);
                }
                if (it2 != s1.end()) {
                    s1.erase(it2);
                } else {
                    s2.insert(s);
                }
            }
            i++;
            total++;
        } while (s1.size() > 0);

        cout << total << endl;
    }

    return 0;
}