#include <iostream>
#include <string>

using namespace std;

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    int memo[word1.size() + 1][word2.size() + 1];
    
    for (int i = 0; i <= word1.size(); i++)
        memo[i][0] = 0;

    for (int i = 0; i <= word2.size(); i++)
        memo[0][i] = 0;

    for (int i = 0; i < word1.size(); i++) {
        for (int j = 0; j < word2.size(); j++) {
            if (word1[i] == word2[j])
                memo[i + 1][j + 1] = memo[i][j] + 1; 
            else
                memo[i + 1][j + 1] = max(memo[i + 1][j], memo[i][j + 1]);
        }
    }

    cout << memo[word1.size()][word2.size()] << endl;
    
    return 0;
}