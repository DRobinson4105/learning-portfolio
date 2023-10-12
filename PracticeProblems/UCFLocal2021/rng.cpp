#include <iostream>
#include <vector>

using namespace std;

int inverseMod(int a, int b) {
    int num = 1;

    while ((num * a) % b != 1)
        num++;
        
    return (num % b);
}

int main() {
    int n, d, w, l, tmp;
    cin >> n >> d >> w >> l;

    int p = 0;
    int q = 0;

    vector<int> board(n);

    for (int i = 0; i < w; i++) {
        cin >> tmp;
        board[tmp] = 1;
    }

    for (int i = 0; i < l; i++) {
        cin >> tmp;
        board[tmp] = -1;
    }

    return 0;
}