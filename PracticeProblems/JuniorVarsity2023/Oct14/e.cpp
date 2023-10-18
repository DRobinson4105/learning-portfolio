#include <iostream>
#include <vector>

using namespace std;

int best = 0;

void solve(vector<int> tasks, vector<bool> tools, int index, int size, int count, int currentTool) {
    if (index == size) {
        best = max(best, count);
        return;
    }

    if (tasks[index] == currentTool) {
        solve(tasks, tools, index + 1, size, count + 1, currentTool);
    } else {
        if (tools[tasks[index]]) {
            tools[currentTool] = false;
            solve(tasks, tools, index + 1, size, count + 1, tasks[index]);
        }
        
        solve(tasks, tools, index + 1, size, count, currentTool);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> tasks(n);
    vector<bool> tools(3, true);

    for (int i = 0; i < n; i++)
        cin >> tasks[i];

    for (int i = 0; i < 3; i++)
        solve(tasks, tools, 0, n, 0, i);

    cout << best << endl;
    return 0;
}