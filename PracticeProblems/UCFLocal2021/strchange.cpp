#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int length = s.size();
    int firstU = 0;
    int firstF = length - 1;

    while (s[firstU] != 'U') firstU++;

    while (s[firstF] != 'F') firstF--;

    for (int i = 0; i < firstU; i++)
        s[i] = '-';

    for (int i = firstU + 1; i < firstF; i++)
        s[i] = 'C';

    for (int i = firstF + 1; i < length; i++)
        s[i] = '-';

    cout << s << endl;

    return 0;
}