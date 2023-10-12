#include <bits/stdc++.h>

using namespace std;

#define WORD_LENGTH 10000

int main()
{
    int numWords;
    char word[WORD_LENGTH + 1];
    cin >> numWords;
    fgets(word, WORD_LENGTH + 1, stdin);
    for(int a = 0; a < numWords; a++)
    {
        fgets(word, WORD_LENGTH + 1, stdin);

        int count = 0;
        for(int i = 0; i < WORD_LENGTH + 1; i++)
        {
            if(word[i] == ' ' || word[i] == '\n')
            {
                cout << (char)(64 + count);
                count = 0;
                if(word[i] == '\n') break;
            }
            else
            {
                count++;
            }
        }

        cout << endl;
    }
}