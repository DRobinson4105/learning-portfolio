#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int cases;
    cin >> cases;

    for (int test = 0; test < cases; test++) {
        int n;
        cin >> n;

        vi gnomes(n);
        
        for (int i = 0; i < n; i++) cin >> gnomes[i];

        for (int i = 1; i < n; i++) {
            if (gnomes[i] != gnomes[i - 1] + 1) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}