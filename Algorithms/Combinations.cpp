#include <iostream>
#include <vector>

using namespace std;

void getCombinations(
    vector<vector<int> >& result, vector<int>& array, vector<int>& comb,
    int curr, int combSize, int start, int size
) {
    if (curr == combSize) {
        result.push_back(comb);
    } else {
        for (int i = start; i < size && size - i >= combSize - curr; i++) {
            comb[curr] = array[i];
            getCombinations(result, array, comb, curr + 1, combSize, i + 1, size);
        }
    }
}

int main() {
    int size = 8;
    int combSize = 4;
    vector<int> array(size);
    vector<int> comb(combSize);
    vector<vector<int> > result;

    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    getCombinations(result, array, comb, 0, combSize, 0, size);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }
}