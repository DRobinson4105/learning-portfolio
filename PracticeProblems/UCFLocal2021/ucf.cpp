#include <iostream>
#include <vector>

using namespace std;

long long int fact(int num) {
    long long int res = 1;

    for (int i = 2; i <= num; i++)
        res *= i;

    return res;
}

int main() {
    int n, x, y, t;

    cin >> n;

    vector<pair<int, int>> sites(n);

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        sites[i] = make_pair(x, y);
    }

    cin >> t;

    for (int trip = 0; trip < t; trip++) {
        
    }
    return 0;
}