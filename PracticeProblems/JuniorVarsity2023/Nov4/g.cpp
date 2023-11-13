#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef long long ll;

string convertToString(ll first, ll second) {
    return to_string(first) + " " + to_string(second);
}

int main() {
    unordered_map<string, ll> counts;
    int n, result = 0;
    cin >> n;

    for (int p = 0; p < n; p++) {
        ll x, y;
        cin >> x >> y;

        if (counts.find(convertToString(x, y)) != counts.end())
            result += counts[convertToString(x, y)];
        
        string pairs[12];
        pairs[0] = convertToString(x + 2018, y);
        pairs[1] = convertToString(x - 2018, y);
        pairs[2] = convertToString(x, y + 2018);
        pairs[3] = convertToString(x, y - 2018);
        pairs[4] = convertToString(x + 1680, y + 1118);
        pairs[5] = convertToString(x + 1680, y - 1118);
        pairs[6] = convertToString(x - 1680, y + 1118);
        pairs[7] = convertToString(x - 1680, y - 1118);
        pairs[8] = convertToString(x + 1118, y + 1680);
        pairs[9] = convertToString(x + 1118, y - 1680);
        pairs[10] = convertToString(x - 1118, y + 1680);
        pairs[11] = convertToString(x - 1118, y - 1680);

        for (string pair : pairs) {
            if (counts.find(pair) == counts.end())
                counts[pair] = 0;

            counts[pair]++;
        }
    }

    cout << result << endl;
    return 0;
}