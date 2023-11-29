#include <bits/stdc++.h>

using namespace std;

void permute(vector<string> items, vector<string> perm, int index, int curr, int N, int K) {
    if (curr == K) {
        for (string str : perm)
            cout << str << " ";
        cout << endl;
        return;
    }

    if (index == N) return;

    for (int i = index; i < N; i++) {
        perm[curr] = items[i];
        permute(items, perm, i + 1, curr + 1, N, K);
    }
}

int main() {
    int T;
    cin >> T;

    for (int run = 0; run < T; run++) {
        int N, K;
        cin >> N >> K;

        vector<string> items(N);
        vector<string> perm(K);

        for (int i = 0; i < N; i++) cin >> items[i];

        sort(items.begin(), items.end());
        permute(items, perm, 0, 0, N, K);

        cout << endl;
    }

    return 0;
}