#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

typedef vector<int> vi;

int kadanes(vi row, int n) {
    int highest = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += row[i];
        if (currSum < row[i]) currSum = row[i];
        highest = max(highest, currSum);
    }

    return highest;
}