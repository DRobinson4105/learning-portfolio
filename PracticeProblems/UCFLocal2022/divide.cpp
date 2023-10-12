#include <iostream>
#include <vector>

using namespace std;

int isPair(int num1, int num2) {
    if (num1 == num2)
        return 0;
    if (num1 == 0 || num2 == 0)
        return 1;
    

    return ((double)num1 / num2 == num1 / num2 || (double)num2 / num1 == num2 / num1);
}

int main() {
    int p, count = 0;
    cin >> p;

    vector<int> nums(p);
    for (int i = 0; i < p; i++) cin >> nums[i];

    for (int i = 0; i < p; i++)
        for (int j = i + 1; j < p; j++)
            count += isPair(nums[i], nums[j]);

    cout << count << endl;;
    return 0;
}