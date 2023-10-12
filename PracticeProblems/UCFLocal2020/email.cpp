#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class DS {
    public:
        int* arr;

        DS(int n) {
            arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = -1;
        }

        int find(int x) {
            return (arr[x] < 0) ? x : (arr[x] = find(arr[x]));
        }

        void merge(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);
            
            if (p1 == p2) return;

            arr[p1] += arr[p2];
            arr[p2] = p1;
        }
};

int main() {
    int p, s;
    cin >> p >> s;
    s--;

    vector<string> people(p);
    vector<vector<int>> contacts(p);
    DS chains(p);

    for (int i = 0; i < p; i++)
        cin >> people[i];

    for (int i = 0; i < p; i++) {
        int numContacts;
        cin >> numContacts;

        vector<int> cont(p);
        cont[i] = 1;

        for (int j = 0; j < numContacts; j++) {
            int num;
            cin >> num;
            num--;
            
            cont[num] = 1;

            if (num < i && contacts[num][i] == 1)
                chains.merge(num, i);
        }

        contacts[i] = cont;
    }

    

    return 0;
}