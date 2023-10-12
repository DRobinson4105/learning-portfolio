#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string word;
    cin >> word;
    int len = word.size();

    for (int i = 0; i < len - 1; i++) {
        if ((isVowel(word[i]) && isVowel(word[i + 1])) || (!isVowel(word[i]) && !isVowel(word[i + 1]))) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}