#include <iostream>

using namespace std;

int main() {
    int currMax = 0;
    int netLength, numFish;
    int highestX = 0, highestY = 0;
    int water[101][101];
    
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            water[i][j] = 0;
    
    cin >> netLength >> numFish;
    
    for (int i = 0; i < numFish; i++) {
        int x, y;
        cin >> x >> y;
        water[x][y] = 1;
        if (x > highestX)   
            highestX = x;
        if (y > highestY)
            highestY = y;
    }
    
    highestX -= netLength;
    highestY -= netLength;
    if (highestX < 0)
        highestX = 0;
    if (highestY < 0)
        highestY = 0;
    netLength++;

    for (int i = 0; i <= highestX; i++) {
        for (int j = 0; j <= highestY; j++) {
            int sum = 0;
            for (int a = 0; a < netLength; a++)
                for (int b = 0; b < netLength; b++)
                    sum += water[i + a][j + b];

            if (sum > currMax)
                currMax = sum;
        }
    }

    cout << currMax << endl;
    
    return 0;
}