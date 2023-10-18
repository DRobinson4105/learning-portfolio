#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, long int> dp;

long int compute(int width, int height) {
    if (width > height) return 0;
    if (width == 0 || height == 0) return 1;

    int comp = (min(width, height) << 5) + max(width, height);

    if (dp.find(comp) != dp.end()) {
        return dp.at(comp);
    }

    long int result = compute(width - 1, height) + compute(width, height - 1);

    dp[comp] = result;
    return result;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        cout << compute(n, n) << endl;
        cin >> n;
    }

    return 0;
}