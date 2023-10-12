#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> counts(26);

    string word;
    cin >> word;

    for (char c : word)
        counts[c - 'a']++;

    bool odd = false;
    bool even = false;

    for (int count : counts) {
        if (count == 0) continue;
        
        if (count % 2 == 0) even = true;
        else odd = true;
    }

    if (even && odd)
        cout << "0/1" << endl;
    else if (even) 
        cout << 0 << endl;
    else
        cout << 1 << endl;

    return 0;
}