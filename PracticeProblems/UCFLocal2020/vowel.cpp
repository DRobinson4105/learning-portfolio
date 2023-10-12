#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;

    int vowel = 0;
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel++;
        else
            vowel--;
    }

    cout << (int)(vowel > 0) << endl;
}