#include <iostream>

using namespace std;

int main() {
    int numStudents, numBrownies;
    cin >> numStudents >> numBrownies;

    int numGroups;
    cin >> numGroups;

    for (int i = 0; i < numGroups; i++) {
        int group;
        cin >> group;
        while (numBrownies <= group)
            numBrownies *= 2;

        numBrownies -= group;
        cout << group << " " << numBrownies << endl;
    }

    return 0;
}