#include <iostream>
#include <vector>

using namespace std;

int strength;

int moveToNextSpot(int jungle[][1000], vector<int*> monkeys, int index);

int findLowest(int up, int down, int left, int right);

int findHighest(int up, int down, int left, int right);

int main()
{
    int s;
    cin >> s;

    for(int scenario = 0; scenario < s; scenario++)
    {
        int xLength, yLength;
        strength = 0;
        cin >> yLength >> xLength;
        int jungle[1000][1000];
        vector<int*> monkeys;

        for(int j = 0; j < yLength; j++)
        {
            int num;
            int i = 0;
            cin >> num;
            while(num != 0)
            {
                jungle[i][j] = num % 10;
                if(jungle[i][j] == 0)
                {
                    int * location = (int *) malloc(sizeof(int) * 2);
                    location[0] = i;
                    location[1] = j;
                    monkeys.push_back(location);
                }
                i++;
                num /= 10;
            }
        }
        
        for(int monkey = 0; monkey < monkeys.size(); monkey++)
        {

            int x = monkeys[monkey][0];
            int y = monkeys[monkey][1];
            vector<int *> monkeyPath;

            while(x > 0 && x < xLength - 1 && y > 0 && y < yLength - 1)
            {
                x = monkeys[monkey][0];
                y = monkeys[monkey][1];
                int * newSpot = (int *) malloc(sizeof(int) * 2);
                newSpot[0] = x;
                newSpot[1] = y;
                monkeyPath.push_back(newSpot);
                int newStrength = moveToNextSpot(jungle, monkeys, monkey);
                if(newStrength == -1) break;
                if(newStrength > strength) strength = newStrength;
            }

            
            for(int i = 0; i < monkeyPath.size(); i++)
            {
                int currX = monkeyPath[i][0];
                int currY = monkeyPath[i][1];
                jungle[currX][currY] = -1; 
            }
        }
        
        cout << strength << "\n";
    }
    return 0;
}

int moveToNextSpot(int jungle[][1000], vector<int*> monkeys, int index)
{
    int x = monkeys[index][0];
    int y = monkeys[index][1];
    int left = jungle[x - 1][y];
    int right = jungle[x + 1][y]; 
    int up = jungle[x][y + 1];
    int down = jungle[x][y - 1];

    if(left == -1 || right == -1 || up == -1 || down == -1) return -1;
    int lowest = findLowest(up, down, left, right);
    int highest = findHighest(up, down, left, right);

    if(lowest == 0 && highest != 0)
    {
        if((left <= right || right == 0) && (left <= up || up == 0) && (left <= down || down == 0) && left != 0)
        {
            jungle[x - 1][y] = 0;
            monkeys[index][0] = x - 1;
            return left;
        }
        else if((right <= left || left == 0) && (right <= up || up == 0) && (right <= down || down == 0) && right != 0)
        {
            jungle[x + 1][y] = 0;
            monkeys[index][0] = x + 1;
            return right;
        }
        else if(((up <= left || left == 0) && (up <= right || right == 0) && (up <= down || down == 0) && up != 0))
        {
            jungle[x][y + 1] = 0;
            monkeys[index][1] = y + 1;
            return up;
        }
        else
        {
            jungle[x][y - 1] = 0;
            monkeys[index][1] = y - 1;
            return down;
        }
    }
    if(left <= right && left <= up && left <= down)
    {
        jungle[x - 1][y] = 0;
        monkeys[index][0] = x - 1;
        return left;
    }
    else if(right < left && right < up && right < down)
    {
        jungle[x + 1][y] = 0;
        monkeys[index][0] = x + 1;
        return right;
    }
    else if(up < left && up < right && up < down)
    {
        jungle[x][y + 1] = 0;
        monkeys[index][1] = y + 1;
        return up;
    }
    else
    {
        jungle[x][y - 1] = 0;
        monkeys[index][1] = y - 1;
        return down;
    }
}

int findLowest(int up, int down, int left, int right)
{
    if(left <= right && left <= up && left <= down) return left;
    else if(right <= left && right <= up && right <= down) return right;
    else if(up <= left && up <= right && up <= down) return up;
    else return down;
}

int findHighest(int up, int down, int left, int right)
{
    if(left >= right && left >= up && left >= down) return left;
    else if(right >= left && right >= up && right >= down) return right;
    else if(up >= left && up >= right && up >= down) return up;
    else return down;
}