#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int pass1, pass2;
    cin >> pass1 >> pass2;
    int total = 0;
    for (int i = 0; i < 4; i++) {
        if (pass1 % 10 != pass2 % 10)
            total++;
        
        pass1 /= 10;
        pass2 /= 10;
    }

    cout << pow(2, total) << endl;
    return 0;
}