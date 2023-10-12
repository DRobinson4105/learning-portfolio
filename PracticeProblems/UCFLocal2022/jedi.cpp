#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int passedShots;
int jediOneMax, jediTwoMax;

void testOption(int curr, vector<int> shots, int numShots, int currCount, int jediOneCur, int jediTwoCur) {
    if (jediOneCur != 0 && jediTwoCur != 0) currCount++;

    if (curr == numShots - 1) {
        passedShots = min(passedShots, currCount);
        return;
    }
    
    if (jediOneCur != 0 && jediTwoCur != 0) {
        testOption(curr + 1, shots, numShots, currCount, max(jediOneCur - (shots[curr + 1] - shots[curr]), 0), max(jediTwoCur - (shots[curr + 1] - shots[curr]), 0));
        return;
    }

    if (jediOneCur == 0) {
        testOption(curr + 1, shots, numShots, currCount, max(jediOneMax - (shots[curr + 1] - shots[curr]), 0), max(jediTwoCur - (shots[curr + 1] - shots[curr]), 0));
    }
    if (jediTwoCur == 0) {
        testOption(curr + 1, shots, numShots, currCount, max(jediOneCur - (shots[curr + 1] - shots[curr]), 0), max(jediTwoMax - (shots[curr + 1] - shots[curr]), 0));
    }
}

void swap(int* num1, int* num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main() {
    int b, j;
    cin >> b;
    
    vector<int> shots(b);
    for (int i = 0; i < b; i++) cin >> shots[i];

    sort(shots.begin(), shots.end());

    cin >> j;
    
    if (j == 1) {
        passedShots = 0;
        int time;
        cin >> time;
        int curr = 0;
        for (int i = 0; i < b; i++) {
            curr -= shots[i];

            if (curr <= 0)
                curr = time;
            else
                passedShots++;
        }
        
    }
    else {
        passedShots = INT_MAX;
        int jediOneCur = 0, jediTwoCur = 0;
        cin >> jediOneMax >> jediTwoMax;
        testOption(0, shots, b, 0, 0, 0);
    }
    
    cout << passedShots << endl;
    return 0;
}