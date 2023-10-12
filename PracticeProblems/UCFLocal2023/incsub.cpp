#include <iostream>
#include <vector>

using namespace std;

int main() {
    int len;
    cin >> len;

    vector<int> list(len);
    for (int i = 0; i < len; i++) cin >> list[i];

    int count = 1;
    int curr = 0;

    for (int i = 1; i < len; i++) {
        if (list[i] > list[i - 1])
            curr++;
        else
            curr = 0;
        
        count = max(count, curr + 1);
    }    

    cout << max(count, curr) << endl;
    return 0;
}