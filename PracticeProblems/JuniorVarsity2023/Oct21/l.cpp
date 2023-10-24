#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>

using namespace std;

class Spot;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<Spot*> vs;
typedef vector<vs> vvs;
typedef set<pii> spii;

int h, w;

class Spot {
public:
    int numConnected = 0;
    spii connected;
    int color = 0;
    int val;
    int x, y;

    Spot(int i, int j, int val) {
        this->x = i;
        this->y = j;
        this->val = val;
    }
    void black(vvs& grid) {
        this->color = 1;
        for (pii coord : this->connected) {
            grid[coord.first][coord.second]->numConnected--;
            grid[coord.first][coord.second]->connected.erase(make_pair(x, y));
            if (grid[coord.first][coord.second]->numConnected == 0) {
                grid[coord.first][coord.second]->white();
            }
        }
    }

    void white() {
        this->color = -1;
    }
};

bool valid(int i, int j) {
    return i > 0 && i < h - 1 && j > 0 && j < w - 1;
}

void assign(vvs grid, int i, int j, spii& available, spii& black, spii& white) {
    if (!valid(i, j)) return;

    switch (grid[i][j]->color) {
        case -1:
            white.insert(make_pair(i, j));
            break;
        case 0:
            available.insert(make_pair(i, j));
            break;
        case 1:
            black.insert(make_pair(i, j));
            break;
    }
}

void compute(vvs& grid, int i, int j) {
    spii available, black, white;

    for (int m = i - 1; m <= i + 1; m++) {
        for (int n = j - 1; n <= j + 1; n++) {
            assign(grid, m, n, available, black, white);
        }
    }

    int total, numBlack, numWhite, numAvailable;
    numBlack = black.size();
    numWhite = white.size();
    numAvailable = available.size();
    total = numBlack + numWhite + numAvailable;

    if (numBlack + numAvailable < grid[i][j]->val || numBlack > grid[i][j]->val) {
        throw invalid_argument("");
    }
    
    for (pii coord : available) {
        for (pii otherCoord : available) {
            if (coord.first != otherCoord.first || coord.second != otherCoord.second) {
                grid[coord.first][coord.second]->connected.insert(otherCoord);
            }
        }
    }

    if (numBlack == grid[i][j]->val) {
        for (pii coord : available) {
            grid[coord.first][coord.second]->white();
        }
    } else if (numBlack + numAvailable == grid[i][j]->val) {
        for (pii coord : available) {
            grid[coord.first][coord.second]->black(grid);
        }
    } 
}

int main() {
    cin >> h >> w;
    h += 2;
    w += 2;
    vvs grid(h, vs(w));
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int val;
            cin >> val;
            grid[i][j] = new Spot(i, j, val);
        }
    }

    try {
        int lowerY = 0, higherY = h - 1, lowerX = 0, higherX = w - 1;

        while (higherY >= lowerY && higherX >= lowerY) {
            for (int j = lowerX; j <= higherX; j++) {
                compute(grid, lowerY, j);
            }

            lowerY++;

            if (lowerY > higherY) break;

            for (int i = lowerY; i <= higherY; i++) {
                compute(grid, i, higherX);
            }

            higherX--;

            if (lowerX > higherX) break;

            for (int j = higherX; j >= lowerX; j--) {
                compute(grid, higherY, j);
            }

            higherY--;

            if (lowerY > higherY) break;

            for (int i = higherY; i >= lowerY; i--) {
                compute(grid, i, lowerX);
            }

            lowerX++;
        }

        for (int i = 1; i < h - 1; i++) {
            for (int j = 1; j < w - 1; j++) {
                cout << (grid[i][j]->color == 1 ? 'X' : '.');
            }
            cout << endl;
        }
    } catch(invalid_argument& e) {
        cout << "impossible" << endl;
    }

    return 0;
}