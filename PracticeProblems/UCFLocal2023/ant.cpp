#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct anthill {
    int numTunnels;
    int* tunnels;
    int* costs;
};

void compute(vector<anthill*> anthills, vector<int>& best, vector<int>& visited, int curr, int last) {
    cout << curr << endl;
    for (int i = 0; i < best.size(); i++) {
        cout << best[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < visited.size(); i++) {
        cout << visited[i] << " ";
    }
    cout << endl;
    visited[curr] = 1;

    for (int i = 0; i < anthills[curr]->numTunnels; i++) {
        if (best[anthills[curr]->tunnels[i]] != INT_MAX && anthills[curr]->tunnels[i] != last) {
            last = -1;
            break;
        }
    }

    for (int i = 0; i < anthills[curr]->numTunnels; i++) {
        int curTunnel = anthills[curr]->tunnels[i];

        if (curTunnel == last) continue;

        best[curTunnel] = min(best[curTunnel], anthills[curr]->costs[i]);

        if (!visited[curTunnel]) {
            compute(anthills, best, visited, curTunnel, curr);
        }
    }
    for (int i = 0; i < best.size(); i++) {
        cout << best[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < visited.size(); i++) {
        cout << visited[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    int n;
    cin >> n;
    
    for (int camp = 1; camp <= n; camp++) {
        int numAnthills, numTunnels;
        cin >> numAnthills >> numTunnels;

        vector<anthill *> anthills(numAnthills);

        for (int i = 0; i < numAnthills; i++) {
            anthills[i] = (anthill *) malloc(sizeof(anthill));
            anthills[i]->numTunnels = 0;
            anthills[i]->costs = (int *) malloc(sizeof(int) * numAnthills);
            anthills[i]->tunnels = (int *) malloc(sizeof(int) * numAnthills);
        }

        for (int i = 0; i < numTunnels; i++) {
            int a1, a2, c;
            cin >> a1 >> a2 >> c;

            a1--;
            a2--;

            anthills[a1]->tunnels[anthills[a1]->numTunnels] = a2;
            anthills[a1]->costs[anthills[a1]->numTunnels] = c;
            anthills[a1]->numTunnels++;
            anthills[a2]->tunnels[anthills[a2]->numTunnels] = a1;
            anthills[a2]->costs[anthills[a2]->numTunnels] = c;
            anthills[a2]->numTunnels++;
        }

        vector<int> best(numAnthills, INT_MAX);
        vector<int> visited(numAnthills, 0);

        compute(anthills, best, visited, 0, -1);

        int sum = 0;
        for (int i = 1; i < numAnthills; i++) {
            if (best[i] == INT_MAX) {
                sum = -1;
                break;
            }
            sum += best[i];
        }


        cout << "Campus #" << camp << ": ";
        if (sum == -1) {
            cout << "I'm a programmer, not a miracle worker!" << endl;
        } else {
            cout << sum << endl;
        }
    }
    return 0;
}