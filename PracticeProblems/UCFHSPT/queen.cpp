#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numChessboards;
    cin >> numChessboards;
    
    for(int chessboards = 0; chessboards < numChessboards; chessboards++)
    {
        int k;
        cin >> k;
        int ans = (2 * k + 1) * (2 * k + 1) - 8 * k - 1;
        cout << ans << "\n";
    }

    return 0;
}