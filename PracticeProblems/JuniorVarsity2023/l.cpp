#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int starting = n / m;
    int extra = n - starting * m;

    vector<int> schools(m);
    vector<int> result(m);
    vector<bool> stillNeed(m, true);
    int numNeeded = m;

    for (int i = 0; i < m; i++) {
        cin >> schools[i];
        if (starting >= schools[i]) {
            extra += starting - schools[i];
            stillNeed[i] = false;
            numNeeded--;
        }
        result[i] = min(schools[i], starting);
    }

    for (int i = 0; i < m; i++) {
        cout << result[i] << endl;
    }

    return 0;
}