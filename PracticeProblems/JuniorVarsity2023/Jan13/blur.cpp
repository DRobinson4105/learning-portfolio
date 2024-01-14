#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;

int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

vvd blurImage(vvd grid, int w, int h) {
    vvd res(h, vd(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            double curr = grid[i][j];
            for (int k = 0; k < 8; k++) {
                int nX = (i + dx[k]) % h;
                int nY = (j + dy[k]) % w;
                if (nX < 0) nX += h;
                if (nY < 0) nY += w;

                curr += grid[nX][nY];
            }

            res[i][j] = curr / 9;
        }
    }

    return res;
}

int main() {
    int w, h, b; cin >> w >> h >> b;
    vvd grid(h, vd(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];

    while (b--) {
        grid = blurImage(grid, w, h);
    }

    unordered_set<double> used;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            grid[i][j] *= 1e10;
            used.insert(floor(grid[i][j]));
        }
    }

    cout << used.size() << endl;
    return 0;
}