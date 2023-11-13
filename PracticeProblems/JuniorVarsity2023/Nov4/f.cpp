#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;

// left, up, right, down
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

bool test(vector<int> instructions, int x, int y) {
    int cX = 0, cY = 0, dir = 1;

    for (int instruction : instructions) {
        switch(instruction) {
            case 0: dir = (((dir - 1) % 4) + 4) % 4; break;
            case 1: dir = (dir + 1) % 4; break;
            case 2: cX += dirX[dir]; cY += dirY[dir]; break;
        }
    }

    return cX == x && cY == y;
}

int main() {
    int x, y, n; cin >> x >> y >> n;

    vector<int> instructions(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        switch (s[0]) {
            case 'L': instructions[i] = 0; break;
            case 'R': instructions[i] = 1; break;
            case 'F': instructions[i] = 2; break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (instructions[i] == j) continue;

            int t = instructions[i];
            instructions[i] = j;

            if (test(instructions, x, y)) {
                cout << (i + 1) << " " << (instructions[i] == 0 ? "Left" : instructions[i] == 1 ? "Right" : "Forward") << endl;
                return 0;
            }

            instructions[i] = t;
        }
    }
    
    return 0;
}