#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct cell {
    int num, rowSum, colSum;

    cell(int n, int r, int c) : num(n), rowSum(r), colSum(c) {};
};

typedef pair<int, int> pii;
typedef vector<cell> vc;
typedef vector<cell> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;

int compute(vvi grid, int i, int j, int a, int b) {
    int res = grid[a][b];
    if (i) res -= grid[i - 1][b];
    if (j) res -= grid[a][j - 1];
    if (i && j) res += grid[i - 1][j - 1];

    return res;
}

int kadanes(vi row, int n) {
    int highest = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += row[i];
        highest = max(highest, currSum);

        if (currSum < 0) currSum = 0;
    }

    return highest;
}

int main() {
    int k;
    cin >> k;

    for (int test = 0; test < k; test++) {
        int n;
        cin >> n;
        
        vvi grid(n, vi(n));

        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if (i) grid[i][j] += grid[i - 1][j];
            }
        }

        int highest = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vi row(n);
                for (int m = 0; m < n; m++) {
                    row[m] = grid[j][m];
                    if (i) row[m] -= grid[i - 1][m];
                }
                highest = max(highest, kadanes(row, n));
            }
        }

        cout << highest << endl;
    }

    return 0;
}