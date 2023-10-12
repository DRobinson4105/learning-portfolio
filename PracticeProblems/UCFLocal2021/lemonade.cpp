#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int numDays, reqLemons, reqSugar;
    cin >> numDays >> reqLemons >> reqSugar;
    int sugarCount = 0, totalCost = 0;
    int lowestLemonCost = INT_MAX;
    int lowestSugarCost = INT_MAX;

    for (int day = 0; day < numDays; day++) {
        int cupsSold, lemonCost, sugarCost;
        cin >> cupsSold >> lemonCost >> sugarCost;

        lowestLemonCost = min(lowestLemonCost, lemonCost);
        lowestSugarCost = min(lowestSugarCost, sugarCost);

        totalCost += lowestLemonCost * reqLemons * cupsSold;
        int bagsBought = ceil(((cupsSold * reqSugar) - sugarCount) / 80.0);
        cout << ((cupsSold * reqSugar) - sugarCount) << endl;
        totalCost += bagsBought * lowestSugarCost;
        sugarCount += bagsBought * 80;
        sugarCount -= cupsSold * reqSugar;
    }

    cout << totalCost << endl;
}