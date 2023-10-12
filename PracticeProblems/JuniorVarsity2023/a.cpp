#include <iostream>
#include <string>

using namespace std;

int main() {
    int sum = 0;
    char* str = (char* ) malloc(sizeof(char) * 101);
    fgets(str, 100, stdin);

    int length = 0;

    for (length = 0; str[length] >= 32 && str[length] <= 126; length++) {
        sum += str[length];
    }

    cout << (char)(sum / length) << endl;

    return 0;
}