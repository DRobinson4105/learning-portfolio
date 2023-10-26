#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct supporter {
    string name;
    int memberIndex, index;

    supporter(string n, int m, int i) : name(n), memberIndex(m), index(i) {}
};

int main() {
    unordered_map<string, int> members;
    int n, m;
    cin >> n >> m;

    while (n != 0 || m != 0) {
        for (int i = 0; i < n; i++) {
            string member;
            cin >> member;
            members[member] = i;
        }

        vector<supporter*> supporters(m);

        for (int i = 0; i < m; i++) {
            string name, memberName;
            cin >> name >> memberName;

            if (members.find(memberName) == members.end()) {
                members[memberName] = n++;
            }

            supporters[i] = new supporter(name, members[memberName], i);
        }

        sort(supporters.begin(), supporters.end(), [](supporter* a, supporter* b) {
            return (a->memberIndex == b->memberIndex && a->index < b->index) || a->memberIndex < b->memberIndex;
        });

        for (supporter* s : supporters) {
            cout << s->name << endl;
        }

        cin >> n >> m;
    }

    return 0;
}