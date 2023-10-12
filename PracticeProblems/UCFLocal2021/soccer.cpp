#include <iostream>
#include <vector>

using namespace std;

bool flag = false;

void permute(vector<int> perm, vector<int> used, vector<int> ref, int curr) {
    if (flag) return;

    if (curr == 5) {
        if (perm[0] == perm[1] + perm[2] + perm[3] && perm[4] == perm[1] * 3 + perm[2]) {
            for (int num : perm)
                cout << num << " ";
            cout << endl;
            flag = true;
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (used[i]) continue;

        used[i] = 1;
        perm[curr] = ref[i];
        permute(perm, used, ref, curr + 1);
        used[i] = 0;
    }
}

int main() {
    vector<int> ref(5);
    vector<int> perm(5);
    vector<int> used(5);

    for (int i = 0; i < 5; i++)
        cin >> ref[i];

    permute(perm, used, ref, 0);

    return 0;
}