#include <iostream>

using namespace std;

int main() {
    int goldUSA, silverUSA, bronzeUSA, goldRussia, silverRussia, bronzeRussia;
    cin >> goldUSA >> silverUSA >> bronzeUSA >> goldRussia >> silverRussia >> bronzeRussia;

    int countUSA = goldUSA + silverUSA + bronzeUSA;
    int countRussia = goldRussia + silverRussia + bronzeRussia;
    int colorUSA;
    int colorRussia;
    if (goldUSA != goldRussia) {
        colorUSA = goldUSA;
        colorRussia = goldRussia;
    }
    else if (silverUSA != silverRussia) {
        colorUSA = silverUSA;
        colorRussia = silverRussia;
    }
    else {
        colorUSA = bronzeUSA;
        colorRussia = bronzeRussia;
    }


    if (countUSA > countRussia && colorUSA > colorRussia)
        cout << "both" << endl;
    else if (countUSA > countRussia)
        cout << "count" << endl;
    else if (colorUSA > colorRussia)
        cout << "color" << endl;
    else
        cout << "none" << endl;

    return 0;
}