#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int curr, prev;
    int count = 1;
    cin >> prev;
    for(int i = 1; i < n; i++)
    {
        cin >> curr;
        if (curr != prev) count++;
        prev = curr;
    }
    cout << count << endl;
    return 0;
}