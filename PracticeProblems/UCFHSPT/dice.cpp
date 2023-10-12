#include <iostream>

using namespace std;

double tryNumber(int curr, int target, int numSides) {
    double chance = 0;
    for (int i = 1; i <= numSides; i++) {
        if (curr + i == target)
            chance += 1.0 / numSides;
        
        else if (curr + i < target)
            chance += tryNumber(curr + i, target, numSides) / numSides;
    }

    return chance;
}

int main() {
    int numSides, numGames;
    cin >> numSides >> numGames;

    for (int i = 0; i < numGames; i++) {
        int target;
        cin >> target;
        cout << 100 * tryNumber(0, target, numSides) << endl;
    }

    return 0;
}