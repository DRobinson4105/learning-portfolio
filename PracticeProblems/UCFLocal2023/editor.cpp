#include <iostream>
#include <vector>

using namespace std;

int main() {
    int f;
    cin >> f;

    vector<int> lines(f);
    for (int i = 0; i < f; i++) cin >> lines[i];

    int currR, currC, targR, targC;
    cin >> currR >> currC >> targR >> targC;

    auto change = (currR > targR) ? [](int num) { return num - 1; } : [](int num) { return num + 1; };

    int count = 0;
    int 
    
    return 0;
}