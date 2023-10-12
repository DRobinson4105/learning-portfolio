#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int col, row;

    int dy[4] = {0, 0, 1 ,-1};
    int dx[4] = {1, -1, 0, 0};

    cin >> row >> col;

    char grid[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            char temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }

    int min, max;

    min = 0; 
    max = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //If there is a P at that position
            if(grid[i][j] == 'P')
            {
                int count = 0;
                //check all neighboring indicies
                char solution;
                   
                    //add 1, -1 or 0 to the x's and y's
                    if(i < row - 1 && grid[i+1][j] == '#')
                        count++;
                    if(i > 0 && grid[i-1][j] == '#')
                        count++;
                    if(j+1 < col && grid[i][j+1] == '#')
                        count++;
                    if(j-1 >= 0 && grid[i][j-1] == '#')
                        count++;

                //it only neighbors one hashtag
                if (count == 1)
                {
                    max++;
                    
                }
                //it neighbors more than one # (cant be a guard)
                else if(count > 1)
                {
                    min++;
                    max++;
                }
            }
        }
    }
    cout << min << " " << max << endl;
    return 0;
}