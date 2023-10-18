#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    //Run the program for t times
    for (int i = 0; i < t; i++)
    {
        int numWords;
        cin >> numWords;

        //Create a vector to store the words
        vector<string> words;
        for (int j = 0; j < numWords; j++)
        {
            string word;
            cin >> word;
            words.push_back(word);
        }

        //Count the number of lowercase letters in each word
        int lowercaseCount = 0;
        int uppercaseCount = 0;
        for (int j = 0; j < numWords; j++)
        {
            for (int k = 0; k < words[j].length(); k++)
            {
                if (words[j][k] >= 'a' && words[j][k] <= 'z')
                {
                    lowercaseCount++;
                }
                else
                {
                    uppercaseCount++;
                }
            }
        }

        if (lowercaseCount == uppercaseCount)
            cout << "Sentence #" << i+1 << ": Yes" << endl;
        else
            cout << "Sentence #" << i+1 << ": No" << endl;

    }
}