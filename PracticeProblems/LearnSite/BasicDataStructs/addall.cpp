#include <iostream>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int inp = 0; inp < T; inp++) {
        int N;
        long long int total = 0;
        cin >> N;

        priority_queue<long long int, vector<long long int>, greater<long long int>> nums;

        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            nums.push(num);
        }

        while (nums.size() >= 2) {
            int num1 = nums.top(); nums.pop();
            int num2 = nums.top(); nums.pop();

            total += num1 + num2;
            nums.push(num1 + num2);
        }

        cout << total << endl;
    }

    return 0;
}