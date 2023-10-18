#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int game = 0; game < t; game++)
    {
        char r[10000];
        char m[10000];
        int p = 0, q = 0;
        cin >> r;
        cin >> m;
        int len = strlen(r);

        for(int i = 0; i < len; i++)
        {
            char * temp = (char *) calloc(len - 1, sizeof(char));
            int curr = 0;

            for(int j = 0; j < len; j++)
            {
                if(j != i)
                {
                    temp[curr] = r[j];
                    curr++;
                }
            }

            int equal = 1;

            for(int j = 0; j < len - 1; j++)
            {
                if(m[j] != temp[j])
                {
                    equal = 0;
                    break;
                }
            }

            if(equal == 1) p++;
            q++;

        }

        if(p == 0)
        {
            cout << "0/1\n";
        }
        else
        {
            int GCF;
            for(int i = p; i >= 1; i--)
            {
                if(p % i == 0 && q % i == 0)
                {
                    GCF = i;
                    break;
                }
            }
            cout << (p / GCF) << "/" << (q / GCF) << "\n";
        }
    }
    return 0;
}