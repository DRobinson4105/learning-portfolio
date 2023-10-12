#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numClans;
    cin >> numClans;
    
    for(int clan = 0; clan < numClans; clan++)
    {
        int numDays;
        cin >> numDays;

        int favor = 0;
        int ovoos = 0;

        char curr[8];
        for(int day = 0; day < numDays; day++)
        {
            cin >> curr;
            if(strcmp(curr, "WORK") == 0)
            {  
                ovoos++;
            }    
            else
            {
                favor += ovoos;
                cout << favor << "\n";
            }   
        }
    }

    return 0;
}