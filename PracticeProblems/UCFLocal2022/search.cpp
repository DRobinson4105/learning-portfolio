#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, 1, -1};

int r, w;

void search(vector<string> grid, vector<pair<int, int> > possibleStarts, string word) {
    int len = word.size();
    int numPossible = possibleStarts.size();
    for (auto startPair : possibleStarts) {
        cout << startPair.first << " " << startPair.second << endl;
        int flag = 1;
        int validDirections[4] = {1, 1, 1, 1};
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < 4; k++) {
                if(!validDirections[k]) continue;

                int x = (startPair.first + dirX[k] * j) % r;
                if (x < 0) x += r;
                int y = (startPair.second + dirY[k] * j) % w;
                if (y < 0) y += w;
                if (grid[x][y] != word[j]) {
                    validDirections[k] = 0;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            if (validDirections[i]) {
                switch(i) {
                    case 0:
                        cout << "D ";
                        break;
                    case 1:
                        cout << "U ";
                        break;
                    case 2:
                        cout << "R ";
                        break;
                    default:
                        cout << "L ";
                        break;
                }
                return;
            }
        }
    }
}


int main() {
    cin >> r >> w;
    vector<string> grid(r);
    vector<vector<pair<int, int> > > startingCoords(26);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            startingCoords[grid[i][j] - 'A'].push_back(make_pair(i, j));
        }
    }

    int n;
    cin >> n;
    string word;
    
    for (int i = 0; i < n; i++) {
        cin >> word;
        search(grid, startingCoords[word[0] - 'A'], word);
    }
    
    return 0;
}