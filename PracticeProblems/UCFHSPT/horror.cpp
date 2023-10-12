#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    char msg[101];
    fgets(msg, 101, stdin);
    int flag = 0;
    for (int i = 1; i < 100 && msg[i] != '\0'; i++)
    {
        if(msg[i] == msg[i - 1])
        {
            cout << "No sleep here." << endl;
            flag = 1;
            break;
        }
    }
    if(!flag)
        cout << "Goodnight!" << endl;
    return 0;
}