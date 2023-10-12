#include <iostream>

using namespace std;

int main() {
    int catYears, catMonths;
    cin >> catYears >> catMonths;
    catMonths += catYears * 12;
    int humanYears = 0;
    int humanMonths = 0;

    if (catMonths < 12) {
        humanMonths = catMonths * 15;
    }
    else {
        humanMonths += 15 * 12;
        catMonths -= 12;
        if (catMonths < 12) {
            humanMonths += catMonths * 9;
        }
        else {
            humanMonths += 12 * 9;
            catMonths -= 12;
            humanMonths += catMonths * 4;
        }
    }

    int tmp = humanMonths;
    humanMonths = tmp % 12;
    humanYears = tmp / 12;
    cout << humanYears << ' ' << humanMonths << endl;

    return 0;
}