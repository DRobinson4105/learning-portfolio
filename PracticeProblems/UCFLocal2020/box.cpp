#include <iostream>
#include <vector>

using namespace std;

int main() {
    int length, numBlocks;
    cin >> length >> numBlocks;

    vector<int> grid(length);
    
    for (int i = 0; i < numBlocks; i++) {
        int h, v, c;
        cin >> h >> v >> c;
        c--;

        int highest = 0;
        for (int i = c; i < c + h; i++)
            highest = max(highest, grid[i]);

        for (int i = c; i < c + h; i++)
            grid[i] = highest + v;
    }

    int highest = 0;
    for (int i = 0; i < length; i++)
        highest = max(highest, grid[i]);

    cout << highest << endl;

    return 0;
}