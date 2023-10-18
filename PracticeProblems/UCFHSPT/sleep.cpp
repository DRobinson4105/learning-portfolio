#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int times;
    cin >> times;
    char dump[20];
    fgets(dump, 20, stdin);
    
    for(int a = 0; a < times; a++)
    {
        char s[101];
        fgets(s, 101, stdin);
        int len = strlen(s);
        int count = 0;
        for(int i = 0; i < len; i++)
            if(s[i] == 'z') count++;

        if(count >= 3)
            cout << "Time to take a nap.\n";
        else
            cout << "Perry saves the day!\n";
    }

    return 0;
}