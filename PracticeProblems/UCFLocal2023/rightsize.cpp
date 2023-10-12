#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

map<string, long long int*> employees;

struct compare {
    bool operator()(string const& a, string const& b) const noexcept {
        if (*(employees[a]) == *(employees[b])) {
            return a.compare(b) > 0;
        }
        return *(employees[a]) < *(employees[b]);
    }
};

bool comp(string const& a, string const& b) {
        if (*(employees[a]) == *(employees[b])) {
            return a.compare(b) > 0;
        }
        return *(employees[a]) < *(employees[b]);
    }

int main() {
    int numEmp, numActions;
    cin >> numEmp >> numActions;

    priority_queue<string, vector<string>, decltype(comp)> pq;
    vector<long long int> stored(numEmp);
    vector<pair<string, long long int>> fired;

    for (int i = 0; i < numEmp; i++) {
        string employee;
        long long int salary;
        cin >> employee >> salary;
        stored[i] = salary;
        employees[employee] = &(stored[i]);
        pq.push(employee);
    }

    for (int act = 0; act < numActions; act++) {
        int action;
        cin >> action;

        if (action == 1) {
                string employee;
                long long int amount;
                cin >> employee >> amount;

                *(employees[employee]) += amount;
        } else {
                cout << pq.top() << " " << *(employees[pq.top()]) << endl;
                pq.pop();
                cout << *(employees[pq.top()]) << endl;
        }
    }
    return 0;
}