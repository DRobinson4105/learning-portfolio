#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

bool is_balanced(string s) {
    int vowels = 0;
    int consonants = 0;
    for (char c : s) {
        if (is_vowel(c))
            vowels++;
        else
            consonants++;
    }

    return vowels == consonants;
}

bool string_balanced(string s) {
    int length = s.size();
    for (int len = 2; len <= length; len += 2) {
        for (int i = 0; i <= length - len; i++) {
            if (!is_balanced(s.substr(i, len)))
                return false;
        }
    }

    return true;
}

long long int permute(string s, int curr, int length) {
    if (curr == length) {
        return string_balanced(s);
    }

    if (s[curr] != '?')
        return permute(s, curr + 1, length);

    else {
        long long int total;
        s[curr] = 'a';
        long long int vowels = permute(s, curr + 1, length);
        s[curr] = 'b';
        long long int cons = permute(s, curr + 1, length);
        total = vowels * 6 + cons * 20;
        return total;
    }
}

int main() {
    string s;
    cin >> s;
    long long int count = permute(s, 0, s.size());
    cout << count << endl;
    return 0;
}