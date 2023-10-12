#include <vector>
#include <iostream>

using namespace std;

int cheapestCost = INT_MAX;

void permute(vector<int> usedLectures, vector<vector<int> > lectureCosts, int totalTeachers, int totalLectures, int numUsed, int currCost) {
    if (totalLectures == numUsed) {
        if (currCost < cheapestCost)
            cheapestCost = currCost;

        return;
    }

    int possibleLectures = min(totalLectures - numUsed, 3);

    for (int i = 0; i < totalTeachers; i++) {
        if (usedLectures[i]) continue;

        for (int j = 1; j <= possibleLectures; j++) {
            usedLectures[i] = 1;

            permute(usedLectures, lectureCosts, totalTeachers, totalLectures, numUsed + j, currCost + lectureCosts[i][j - 1]);

            usedLectures[i] = 0;
        }
    }
}

int main() {
    int L, T;
    
    cin >> L >> T;

    vector<vector<int> > lectureCosts(T);

    for (int i = 0; i < T; i++) {
        vector<int> teacher(3);
        cin >> teacher[0] >> teacher[1] >> teacher[2];
        lectureCosts[i] = teacher;
    }

    vector<int> usedLectures(T);

    permute(usedLectures, lectureCosts, T, L, 0, 0);

    cout << cheapestCost << endl;

    return 0;
}