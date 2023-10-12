#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.size();
    int len2 = s2.size();

    int i1 = 1;
    int i2 = len2 - 2;

    while (i1 < len1 && !isVowel(s1[i1]))
        i1++;

    while (i2 > -1 && !isVowel(s2[i2]))
        i2--;

    cout << s1.substr(0, i1) << (isVowel(s2[i2]) ? s2[i2] : (isVowel(s1[i1]) ? s1[i1] : 'o')) << s2.substr(i2 + 1, len2 - i2 - 1) << endl;
    return 0;
}