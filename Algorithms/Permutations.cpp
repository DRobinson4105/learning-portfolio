#include <iostream>
#include <vector>

using namespace std;

void getPermutations(
    vector<vector<int> >& result, vector<bool>& used, 
    vector<int>& array, vector<int>& perm, int curr, int size
) {
    if (curr == size)
        result.push_back(perm);
    else {
        for (int i = 0; i < size; i++) {
            if (used[i]) continue;

            used[i] = true;
            perm[curr] = array[i];
            getPermutations(result, used, array, perm, curr + 1, size);
            used[i] = false;
        }
    }
}

int main() {
    int size = 8;
    vector<int> array(size);
    vector<bool> used(size, false);
    vector<int> perm(size);
    vector<vector<int> > result;

    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    getPermutations(result, used, array, perm, 0, size);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }
}