#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(int x) {
    return x >= 0 && x < 8;
}

void swap(vector<string> grid, int x1, int y1, int x2, int y2) {
    char tmp = grid[x1][y1];
    grid[x1][y1] = grid[x2][y2];
    grid[x2][y2] = tmp;
}

int checkPiece(vector<string> grid, int x, int y, bool checkX, bool checkY, bool notStarting, vector<vector<bool>>& searched) {    
    int total = 0;
    if (grid[x][y] == 'a' || searched[x][y]) return 0;

    searched[x][y] = true;

    if (checkX) {
        int len = 1;
        for (int i = x + 1; isValid(i) && grid[i][y] == grid[x][y]; i++)
            len++;
        for (int i = x - 1; isValid(i) && grid[i][y] == grid[x][y]; i--)
            len++;
        
        if (len >= 3) {
            if (len == 3)
                total += 100;
            else if (len == 4)
                total += 200;
            else
                total += 400;

            if (notStarting)
                total += 1000;
            
            for (int i = x + 1; isValid(i) && grid[i][y] == grid[x][y]; i++)
                searched[i][y] = true;
            for (int i = x - 1; isValid(i) && grid[i][y] == grid[x][y]; i--)
                searched[i][y] = true;

            for (int i = x + 1; isValid(i) && grid[i][y] == grid[x][y]; i++)
                checkPiece(grid, i, y, false, true, true, searched);
            for (int i = x - 1; isValid(i) && grid[i][y] == grid[x][y]; i--)
                checkPiece(grid, i, y, false, true, true, searched);
        }
    }


    if (checkY) {
        int len = 1;
        for (int j = y + 1; isValid(j) && grid[x][j] == grid[x][y]; j++)
            len++;
        for (int j = x - 1; isValid(j) && grid[x][j] == grid[x][y]; j--)
            len++;
        
        if (len >= 3) {
            if (len == 3)
                total += 100;
            else if (len == 4)
                total += 200;
            else
                total += 400;

            if (notStarting)
                total += 1000;
            
            for (int j = y + 1; isValid(j) && grid[x][j] == grid[x][y]; j++)
                searched[x][j] = true;
            for (int j = x - 1; isValid(j) && grid[x][j] == grid[x][y]; j--)
                searched[x][j] = true;

            for (int j = y + 1; isValid(j) && grid[x][j] == grid[x][y]; j++)
                checkPiece(grid, x, j, true, false, true, searched);
            for (int j = x - 1; isValid(j) && grid[x][j] == grid[x][y]; j--)
                checkPiece(grid, x, y, true, false, true, searched);
        }
    }

    return total;
}

pair<int, bool> popPieces(vector<string> grid) {
    int total = 0;
    vector<vector<bool>> searched(8, vector<bool>(8, false));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            total += checkPiece(grid, i, j, true, true, false, searched);
            // int val = checkPiece(grid, i, j, true, true, false, searched);
            // cout << val << endl;
            // total += val;
        }
    }

    for (int i = 7; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            if (searched[i][j] == true) {
                for (int k = i; k > 0; k--) {
                    grid[k][j] = grid[k - 1][j];
                }
                grid[0][j] = 'a';
            }
        }
    }

    return make_pair(total, total);
}

int compute(vector<string> grid, int x1, int y1, int x2, int y2) {
    swap(grid, x1, y1, x2, y2);
    int total = 0;
    bool continueExecuting = true;
    while (continueExecuting) {
        pair<int, bool> res = popPieces(grid);
        continueExecuting = res.second;
        total += res.first;
    }

    return total;
}

int main() {
    int n;
    cin >> n;

    for (int inp = 0; inp < n; inp++) {
        vector<string> grid(8);

        for (int i = 0; i < 8; i++) {
            cin >> grid[i];
        }

        int best = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (isValid(i + 1))
                    best = max(best, compute(grid, i, j, i + 1, j));
                if (isValid(j + 1))
                    best = max(best, compute(grid, i, j, i, j + 1));
            }
        }

        cout << best << endl;
    }

    return 0;
}