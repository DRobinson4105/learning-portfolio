#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int r, s;
    cin >> r >> s;
    
    double ans;

    if (2 * r > s)
        ans = 1;
    else
        ans = ((s * s) - pow((s - 2 * r), 2)) / (s * s);

    printf("%0.11lf\n", ans);
    return 0;
}