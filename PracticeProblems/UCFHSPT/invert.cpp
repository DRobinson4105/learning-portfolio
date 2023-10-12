// Done

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int numWorlds;
    cin >> numWorlds;

    for (int world = 0; world < numWorlds; world++)
    {
        int numRows, numColumns, maxClimb, count = 0;
        cin >> numRows >> numColumns >> maxClimb;

        int ** grid = (int **) malloc(sizeof(int *) * numRows);
        int * heights = (int *) calloc(numColumns, sizeof(int));
        int * invertedHeights = (int *) calloc(numColumns, sizeof(int));
	int inverted = 0;

        for(int i = 0; i < numRows; i++)
        {
            grid[i] = (int *) calloc(numColumns, sizeof(int));

            for(int j = 0; j < numColumns; j++)
            {
                char input;
                cin >> input;
                if(input == '.')
                    grid[i][j] = 1;
            }
        }

        for(int col = 0; col < numColumns; col++)
        {
            int curr = numRows - 1;
            while (grid[curr - 1][col] == 0) 
                curr--;

            heights[col] = numRows - curr - 1;
        }

        for(int i = 0; i < numColumns; i++)
            invertedHeights[i] = numColumns - heights[i];

        for(int i = 0; i < numColumns - 1; i++)
        {
            if (inverted == 0 && heights[i + 1] - heights[i] > maxClimb)
            {
                count++;
              	inverted = 1;
            }
	        else if (inverted == 1 && invertedHeights[i + 1] - invertedHeights[i] > maxClimb)
            {
                count++;
                inverted = 0;
            }
        }
        
        printf("World #%d: %d\n", world + 1, count);
    }

    return 0;
}