#include <iostream>
#include <vector>

using namespace std;

bool on(int mask, int pos) {
    return (mask & (1 << pos)) > 0;
}

int set(int mask, int pos) {
    return mask | (1 << pos);
}

vector<vector<int>> findSubsets(vector<int> array) {
    int numElements = array.size();
    int numSubsets = 1 << numElements;
    vector<vector<int>> subsets(numSubsets);

    for (int mask = 0; mask < numSubsets; mask++) {
        vector<int> subset;

        for (int k = 0; k < numElements; k++)
            if (on(mask, k))
                subset.push_back(array[k]);

        subsets[mask] = subset;
    }

    return subsets;
}

vector<vector<int> > subsets(vector<int>& array) {
    calcSubsets(array, result, 0, array.size());
    return result;
}

int main() {
    vector<int> array(4);

    for (int i = 0; i < 4; i++) {
        array[i] = i + 1;
    }

    vector<vector<int> > result = subsets(array);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}