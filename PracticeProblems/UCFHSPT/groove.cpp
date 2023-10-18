#include <iostream>
#include <stdlib.h>

using namespace std;

int checkFlow(int * notes, int numNotes, int flowLevel);

int main()
{
    int times;
    cin >> times;
    
    for(int a = 0; a < times; a++)
    {
        int numNotes;
        cin >> numNotes;
        int * notes = (int *) malloc(sizeof(int) * numNotes);
        for(int i = 0; i < numNotes; i++)
            cin >> notes[i];

        int highest = 1;
        int valid = 1;
        while(valid == 1)
        {
            if(checkFlow(notes, numNotes, highest) == 1)
                highest++;
            else
                valid = 0;
        }

        cout << (highest - 1) << "\n";
    }

    return 0;
}

int checkFlow(int * notes, int numNotes, int flowLevel)
{
    int valid = 0;
    int curr = 1;
    int mid = 0;
    for(int i = 0; i < numNotes; i++)
    {
        if(curr > flowLevel)
        {
            mid = i;
            break;
        }
        if(notes[i] == curr)
            curr++;
    }

    curr -= 1;
    
    if(curr != flowLevel) return 0;

    for(int i = mid; i < numNotes; i++)
    {
        if(notes[i] == curr)
            curr--;
    }

    if(curr == 0) return 1;
    return 0;
}