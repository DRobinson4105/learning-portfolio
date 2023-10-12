#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int t, s;
    cin >> t >> s;
    vector<int> seq(s);
    
    for (int i = 0; i < s; i++) cin >> seq[i];

    long long int count = 0;
    long long int curr = seq[0];

    for (int i = 1; i < s; i++) {
        curr++;
        long long int distance;
        if (abs(curr - seq[i]) < t / 2.0)
            distance = abs(curr - seq[i]);
        else
            distance = t - abs(curr - seq[i]);
        curr = seq[i];
        count += distance;
    }

    cout << count << endl;
    return 0;
}