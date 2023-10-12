#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int count = 0;
    if (n1 >= 10)
        count++;
    if (n2 >= 10)
        count++;
    if (n3 >= 10)
        count++;

    vector<string> res = {"zilch", "double", "double-double", "triple-double"};

    cout << res[count] << endl;
    
    return 0;
}