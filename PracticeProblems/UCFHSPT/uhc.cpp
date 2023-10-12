#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double * prob = (double *) malloc(sizeof(double) * n);
    int * times = (int *) malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> prob[i];
        prob[i] = 1 / prob[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> times[i];
    }
    
    double total = 0;
    double curr;
    for(int i = 0; i < n; i++)
    {
        curr = times[i];
        for(int j = i; j < n; j++)
        {
            curr *= prob[j];
        }
        total += curr;
    }

    printf("%0.10lf\n", total);
    return 0;
}