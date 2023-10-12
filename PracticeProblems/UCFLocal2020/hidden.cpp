#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count = 0;

void permute(vector<string> words, int currWord, int currLetter, string phrase, int curr, int len) {
    if (currWord == 3) {
        count++;
        return;
    }

    for (int i = curr; i < len; i++) {
        if (phrase[i] == words[currWord][currLetter]) {
            char tmp = phrase[i];
            phrase[i] = '_';
            
            if (currLetter == words[currWord].size() - 1)
                permute(words, currWord + 1, 0, phrase, 0, len);
            else
                permute(words, currWord, currLetter + 1, phrase, i + 1, len);
            
            phrase[i] = tmp;
        }
    }
}

int main() {
    vector<string> words(3);
    string phrase;

    cin >> words[0] >> words[1] >> words[2] >> phrase;

    permute(words, 0, 0, phrase, 0, phrase.size());

    cout << count << endl;

    return 0;
}