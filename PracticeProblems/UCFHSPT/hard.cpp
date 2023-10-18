#include <iostream>

using namespace std;

int main()
{
    int d;
    cin >> d;
    for(int i = 0; i < d; i++)
    {
        int l1, c1, l2, c2;
        cin >> l1 >> c1 >> l2 >> c2;
        int ans = (l1 * c1 > l2 * c2) ? l1 * c1 : l2 * c2;
        cout << ans << "\n";
    }

    return 0;
}