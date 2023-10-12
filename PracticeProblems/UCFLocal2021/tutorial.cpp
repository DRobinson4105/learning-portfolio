#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num = 0;

void solve(vector<int> students, int length, int k, int s, int last) {
    if (last == length) {
        num++;
        return;
    }

    for (int i = last; i < length && i < last + s; i++) {
        if (students[i] - students[last] > k || students[last] - students[i] > k)
            break;

        solve(students, length, k, s, i + 1);
    }
}
int main() {
    int n, k, s;
    cin >> n >> k >> s;
    
    vector<int> students(n);
    for (int i = 0; i < n; i++) cin >> students[i];
    
    sort(students.begin(), students.end());
    solve(students, n, k, s, 0);
    cout << num << endl;
    
    return 0;
}