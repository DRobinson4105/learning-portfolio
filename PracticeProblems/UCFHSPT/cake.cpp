#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int size;
    cin >> size;

    int num = log2(size);
    int sum = 0;
    
    for (int i = 0; i < num; i++)
        sum += pow(2, i);

    cout << sum << endl;
    return 0;
}