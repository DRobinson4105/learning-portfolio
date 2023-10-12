#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compareSecond(pair<double, double>& a, pair<double, double>& b) {
    return a.second < b.second;
}

int validT(vector<pair<double, double> >& coords) {
    vector<pair<double, double> > top3(3);
    int direction = 0;
    int notUsedCoord = 6;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (coords[i].first == coords[j].first && coords[i].first == coords[k].first) {
                    top3 = {coords[i], coords[j], coords[k]};
                    notUsedCoord -= (i + j + k);
                    direction = 1;
                    break;
                }
                if (coords[i].second == coords[j].second && coords[i].second == coords[k].second) {
                    top3 = {coords[i], coords[j], coords[k]};
                    notUsedCoord -= (i + j + k);
                    direction = 2;
                    break;
                }
            }
        }
    }

    if (direction == 0) return 0;

    if (direction == 2)
        sort(top3.begin(), top3.end());
    else
        sort(top3.begin(), top3.end(), compareSecond);

    if (direction == 2 && coords[1].first == coords[notUsedCoord].first &&
        coords[1].second != coords[notUsedCoord].second)
            return 1;

    if (direction == 1 && coords[1].second == coords[notUsedCoord].second &&
        coords[1].first != coords[notUsedCoord].first)
            return 1;

    return 0;
}

void permute(vector<pair<double, double> >& coords, vector<pair<double, double> >& perm,
    vector<int>& used, int curr, int* count, int length, int last) {
        if (curr == 4) {
            *count += validT(perm);
            return;
        }

        for (int i = last + 1; i < length; i++) {
            if (used[i]) continue;

            used[i] = 1;
            perm[curr] = coords[i];
            permute(coords, perm, used, curr + 1, count, length, i);
            used[i] = 0;
        }
}

int main() {
    int p;
    cin >> p;
    vector<pair<double, double> > coords(p);
    vector<pair<double, double> > perm(4);
    vector<int> used(4);
    
    for (int i = 0; i < p; i++) {
        double x, y;
        cin >> x >> y;  
        coords[i] = make_pair(x, y);
    }

    int count = 0;
    permute(coords, perm, used, 0, &count, p, -1);
    cout << count << endl;

    return 0;
}