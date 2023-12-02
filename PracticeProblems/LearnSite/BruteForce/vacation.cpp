#include <bits/stdc++.h>

#define INF 1000000

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<pii> spii;

double distance(pii a, pii b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    cout << setprecision(15);
    int n;
    cin >> n;

    for (int park = 0; park < n; park++) {
        int r, b;
        cin >> r >> b;

        vpii rides(r); 
        spii blocked;
        vvd graph(r, vd(r, INF));

        for (int i = 0; i < r; i++)
            graph[i][i] = 0;

        for (int i = 0; i < r; i++)
            cin >> rides[i].first >> rides[i].second;

        for (int i = 0; i < b; i++) {
            int a, b; cin >> a >> b;
            blocked.insert({a - 1, b - 1});
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < r; j++)
                if (i != j && blocked.count({i, j}) == 0)
                    graph[i][j] = distance(rides[i], rides[j]);

        double bestTime = INF;
        vi perm(r);

        for (int i = 0; i < r; i++)
            perm[i] = i;

        do {
            double time = 0;
            bool validPath = true;
            int prevRide = 0;

            for (int currRide : perm) {
                if (graph[prevRide][currRide] == INF) {
                    validPath = false;
                    break;
                }

                time += graph[prevRide][currRide];
                prevRide = currRide;
            }
            time += distance({0, 0}, rides[perm[0]]) + 120 * r;
            if (validPath) bestTime = min(bestTime, time);
        } while(next_permutation(perm.begin(), perm.end()));
        cout << "Vacation #" << (park + 1) << ":" << endl;
        if (bestTime == INF)
            cout << "Jimmy should plan this vacation a different day." << endl << endl;
        else
            cout << "Jimmy can finish all of the rides in " << (floor(bestTime * 1000 + 0.5)/1000) << " seconds." << endl << endl;

    }

    return 0;
}