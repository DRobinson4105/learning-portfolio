#include <bits/stdc++.h>

using namespace std;

int main()
{
    int numParades;
    cin >> numParades;
    
    for(int parade = 0; parade < numParades; parade++)
    {
        int n, m;
        cin >> n >> m;
        int curr = 1;
        for(int i = 0; i < m; i++)
        {
            curr++;
            if(curr >= n) curr -= n;
        }
        
        cout << curr << "\n";
    }

    return 0;
}