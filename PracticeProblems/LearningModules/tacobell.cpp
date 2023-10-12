#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void permute(vector<string> items, vector<int> perm, vector<int> used, int curr, int N, int K) {
    if (curr == K) {
        for (int i = 0; i < K; i++)
            cout << items[perm[i]] << " ";

        cout << endl;

        return;
    }

    for (int i = (curr) ? perm[curr - 1] + 1 : 0; i < N; i++) {
        if (used[i]) continue;

        used[i] = 1;
        perm[curr] = i;
        permute(items, perm, used, curr + 1, N, K);
        used[i] = 0;
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        vector<string> items(N);
        vector<int> results(K);
        vector<int> used(N);
        
        for (int i = 0; i < N; i++)
            cin >> items[i];

        sort(items.begin(), items.end());

        permute(items, results, used, 0, N, K);
    }
    return 0;
}