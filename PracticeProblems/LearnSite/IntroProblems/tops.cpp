#include <iostream>
#include <queue>
#include <string>
#include <limits.h>

using namespace std;

int main() {
    int n;
    string garbage;
    cin >> n;

    for (int test = 0; test < n; test++) {
        int k;
        int lowest = INT_MAX, highest = INT_MIN;
        priority_queue<int> scores;
        cin >> k;

        for (int score = 0; score < k; score++) {
            cin >> garbage;

            int num;
            cin >> num;

            lowest = min(lowest, num);
            highest = max(highest, num);
            scores.push(num);
        }

        double median;
        if (k % 2 == 0) {
            for (int i = 0; i < k / 2 - 1; i++)
                scores.pop();
            
            median = scores.top();
            scores.pop();
            median += scores.top();
            median /= 2;

        } else {
            for (int i = 0; i < k / 2; i++)
                scores.pop();

            median = scores.top();
        }
        
        cout << "Case #" << test + 1 << ": " << highest << " " << lowest << " " << (median == (int)median ? (int)median : median) << endl;
    }

    return 0;
}