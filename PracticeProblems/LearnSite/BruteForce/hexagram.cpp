#include <bits/stdc++.h>

using namespace std;

int permute(vector<int> nums, vector<int> p, vector<bool> used, int curr, int sum) {
    if (curr == 5)
        sum = p[1] + p[2] + p[3] + p[4];
    if (curr == 8 && sum != p[0] + p[2] + p[5] + p[8]) return 0;
    if (curr == 11 && (sum != p[0] + p[3] + p[6] + p[10] || sum != p[7] + p[8] + p[9] + p[10]))
        return 0;
    if (curr == 12)
        return sum == p[4] + p[6] + p[9] + p[11] && sum == p[1] + p[5] + p[8] + p[11];

    int result = 0;
    for (int i = 0; i < 12; i++) {
        if (used[i]) continue;

        used[i] = true;
        p[curr] = nums[i];
        result += permute(nums, p, used, curr + 1, sum);
        used[i] = false;
    }

    return result;
}

int main() {
    for (int i = 0; i < 479001600; i++) {};
    vector<int> nums(12);
    vector<int> p(12);
    vector<bool> used(12, false);
    int sum = 0;
    for (int i = 0; i < 12; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    while (sum) {
        int result = 0;
        sort(nums.begin(), nums.end());

        cout << permute(nums, p, used, 0, 0) << endl;

        for (int i = 0; i < 12; i++) {
            cin >> nums[i];
            sum += nums[i];
        }   
    }
    return 0;
}