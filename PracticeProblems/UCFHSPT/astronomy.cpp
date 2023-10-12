#include <bits/stdc++.h>

using namespace std;

void shift(int * arr, int num);

void reverse(int * arr, int num);

int equal(int * arr1, int * arr2, int num);

int main()
{
    int numUniverses;
    cin >> numUniverses;
    
    for(int universe = 0; universe < numUniverses; universe++)
    { 
        int saved = 0;
        int num;

        cin >> num;
        
        int * disk1 = (int *) malloc(sizeof(int) * num);
        int * disk2 = (int *) malloc(sizeof(int) * num);

        for(int i = 0; i < num; i++)
            cin >> disk1[i];

        for(int i = 0; i < num; i++)
            cin >> disk2[i];

        for(int i = 0; i < num; i++)
        {
            if(equal(disk1, disk2, num) == 1)
            {
                saved = 1;
                break;
            }

            reverse(disk1, num);

            if(equal(disk1, disk2, num) == 1)
            {
                saved = 1;
                break;
            }

            reverse(disk1, num);
            shift(disk1, num);
            
        }

        if(saved == 1)
            cout << "Saved\n";
        else
            cout << "Doomed\n";

        free(disk1);
        free(disk2);
    }

    return 0;
}

void shift(int * arr, int num)
{
    if(num == 0) return;

    int * newArr = (int *) malloc(sizeof(int) * num);
    for(int i = 0; i < num; i++)
        newArr[i] = arr[i];

    arr[0] = newArr[num - 1];

    for(int i = 1; i < num; i++)
        arr[i] = newArr[i - 1];

    free(newArr);
}

void reverse(int * arr, int num)
{
    if(num == 0) return;

    int * newArr = (int *) malloc(sizeof(int) * num);
    for(int i = 0; i < num; i++)
        newArr[i] = arr[i];

    for(int i = 0; i < num; i++)
        arr[i] = newArr[num - i - 1];

    free(newArr);
}

int equal(int * arr1, int * arr2, int num)
{
    for(int i = 0; i < num; i++)
        if(arr1[i] != arr2[i]) return 0;

    return 1;
}