#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> rows(n);
    vector<int> cols(n);

    int count = 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (rows[x] && cols[y])
            count++;

        rows[x] = 1;
        cols[y] = 1;
    }

    cout << count << endl;
    return 0;
}