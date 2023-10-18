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
        //make a string vector to store the phrase
        //have the vector store "This song’s gonna get stuck inside yo’"
        vector<string> phrase {"This", "song's", "gonna", "get", "stuck", "inside", "yo'"};

        //Collect the number of times the phrase will be repeated
        int n;
        cin >> n;


        //Print the stanza
        cout << "Stanza #" << i + 1  << ":"<< endl;
        //Print the phrase n times
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < phrase.size(); k++)
            {
                cout << phrase[k] << " ";
            }
            cout << endl;
        }

        //Print the word head
        cout << "head" << endl;

    }
}