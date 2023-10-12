#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numBuildings, distance = 100;
    int currBuilding = 0;
    cin >> numBuildings;

    vector<vector<int>> buildings(numBuildings, vector<int>(3));
    for (int i = 0; i < numBuildings; i++)
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];

    sort(buildings.begin(), buildings.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    distance += buildings[0][2] + buildings[numBuildings - 1][2];

    for (int i = 0; i < numBuildings - 1; i++) {
        if (buildings[i][1] + buildings[i][0] != buildings[i + 1][0])
            distance += buildings[i][2] + buildings[i + 1][2];
        else
            distance += abs(buildings[i][2] - buildings[i + 1][2]);
    }

    cout << distance << endl;
    
    return 0;
}