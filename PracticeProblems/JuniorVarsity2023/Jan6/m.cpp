#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool won(vvi grid, int num) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][2] == num)
            return true;
    }
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[2][i] == num)
            return true;
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] == num)
        return true;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] == num)
        return true;

    return false;
}

bool filled(vvi grid) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == 0)
                return false;
    
    return true;
}

int main() {
    int n; cin >> n;

    while (n--) {
        int curr = 0;
        int num; cin >> num;
        vector<int> bits(19, false);

        int dec = 0;
        for (int i = 0; num; i++) {
            dec += (num % 10) * pow(8, i);
            num /= 10;
        }

        for (int i = 0; dec; i++) {
            bits[i] = dec % 2;
            dec >>= 1;
        }

        vvi grid(3, vi(3, 0));
        for (int i = 0; i < 9; i++) {
            if (bits[i]) {
                grid[i / 3][i % 3] = bits[i + 9] + 1;
            }
        }

        if (won(grid, 1))
            cout << "O wins" << endl;
        else if (won(grid, 2))
            cout << "X wins" << endl;
        else if (filled(grid))
            cout << "Cat's" << endl;
        else
            cout << "In progress" << endl;
    }
    
    return 0;
}