#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int numBirthdays;
    string bday;

    cin >> numBirthdays;

    set<string> birthdays;

    for (int i = 0; i < numBirthdays; i++) {
        cin >> bday;
        birthdays.insert(bday);
    }

    cout << birthdays.size() << endl;

    return 0;
}