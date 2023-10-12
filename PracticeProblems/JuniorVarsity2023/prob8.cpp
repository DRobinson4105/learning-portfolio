#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>

using namespace std;

int closest = -1;

bool on(int mask, int pos) {
    return (mask & (1 << pos)) > 0;
}

int set(int mask, int pos) {
    return mask | (1 << pos);
}

void calcSums(vector<int> array, vector<int>& result, int index, int size) {
    long long int total = pow(2, size);
    for (int mask = 0; mask < total; mask++) {
        int sum = 0;
        for (int k = 0; k < size; k++) {
            if (on(mask, k)) {
                sum += array[k];
            }
        }
        result.push_back(sum);
    }
}

vector<int> sums(vector<int> array) {
    vector<int> result;
    calcSums(array, result, 0, array.size());
    return result;
}

int main() {
    for (int t = 0; t < 3; t++) {
        int n;
        cin >> n;

        vector<int> array(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> array[i];
            sum += array[i];
        }

        double half = sum / 2.0;
        vector<int> result = sums(array);
        int size = result.size();
        closest = result[0];
        for (int i = 1; i < size; i++) {
            if (abs(result[i] - half) < abs(closest - half)) {
                closest = result[i];
            }
        }

        cout << round((double)closest * (sum - closest) / 2) << endl; 
    }
}