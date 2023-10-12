#include <iostream>
#include <vector>
#include <map>

using namespace std;

int decrement(int x, int c) {
    return (x == 0) ? c - 1 : x - 1;
}

int increment(int x, int c) {
    return (x == c - 1) ? 0 : x + 1;
}

int main() {
    int c;
    cin >> c;
    int total = c * (c + 1) / 2;
    int cost = 0;
    int curr = 0;
    vector<int> costs(c);
    map<int, int> indexes;
    for (int i = 0; i < c; i++) {
        int num;
        cin >> num;
        indexes[num] = i;
        costs[i] = (i == 0) ? num : (num + costs[i - 1]);
    }

    for (int i = 0; i < c; i++) 

    return 0;
}