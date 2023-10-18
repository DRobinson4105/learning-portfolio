#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int main() {
    int n;
    int last = 0;
    char* c = (char*) malloc(sizeof(char) * 2);
    char* garbage = (char*) malloc(sizeof(char) * 255);
    cin >> n;
    fgets(garbage, 255, stdin);
    for (int i = 0; i < n; i++) {
        last = 0;
        fgets(c, 2, stdin);
        int num = c[0] - '0';
        bool flag = true;
        while (flag && c[0] >= '0' && c[0] <= '9' && num >= last) {
            cout << c[0];
            last = num;
            if (fgets(c, 2, stdin) == NULL)
                flag = false;
            num = c[0] - '0';
        }

        while (flag && c[0] >= '0' && c[0] <= '9' && num <= last) {
            cout << c;
            last = num;
            if (fgets(c, 2, stdin) == NULL)
                flag = false;
            num = c[0] - '0';
        }

        while (flag && c[0] >= '0' && c[0] <= '9') {
            cout << (char)(last + '0');
            if (fgets(c, 2, stdin) == NULL)
                flag = false;
        }

        cout << endl;
    }
    return 0;
}