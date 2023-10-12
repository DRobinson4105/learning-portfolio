#include <queue>
#include <iostream>

using namespace std;

int dirX[8] = {-1, -1, -1,  0,  1,  1,  1,  0};
int dirY[8] = {-1,  0,  1,  1,  1,  0, -1, -1};

class cell {
    public:
        int x, y, cost;
    
        cell(int a, int b) {
            x = a;
            y = b;
            cost = 0;
        }

        cell(int a, int b, int c) {
            x = a;
            y = b;
            cost = c;
        }
};

int main() {
    int numRows, numCols, startRow, startCol, maxEnergy;
    int highest = 0;
    queue<cell> q;
    cin >> numRows >> numCols >> startRow >> startCol >> maxEnergy;

    startRow--;
    startCol--;

    int** maze = new int*[numRows];
    int** visited = new int*[numRows];
    for (int i = 0; i < numRows; i++) {
        maze[i] = new int[numCols];
        visited[i] = new int[numCols];

        for (int j = 0; j < numCols; j++) {
            cin >> maze[i][j];
            visited[i][j] = 0;
        }
    }

    q.push(cell(startRow, startCol));

    while (!q.empty()) {
        cell cur = q.front();
        q.pop();

        if(maze[cur.x][cur.y] > highest)
            highest = maze[cur.x][cur.y];

        if (maze[cur.x][cur.y])
            continue;

        for (int i = 0; i < 8; i++) {
            int newX = cur.x + dirX[i];
            int newY = cur.y + dirY[i];

            if (newX < 0 || newX >= numRows || newY < 0 || newY >= numCols)
                continue;

            if (visited[newX][newY] == 0 || cur.cost + i + 1 < visited[newX][newY]) {
                visited[newX][newY] = cur.cost + i + 1;
                if (visited[newX][newY] <= maxEnergy)
                    q.push(cell(newX, newY, visited[newX][newY]));
            }
        }
    }
    
    cout << highest << endl;

    return 0;
}