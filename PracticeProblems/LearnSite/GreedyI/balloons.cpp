#include <bits/stdc++.h>

using namespace std;

struct team {
    int k, da, db, diff;
    team(int k, int da, int db) : k(k), da(da), db(db), diff(da - db) {}
};

typedef vector<int> vi;
typedef vector<team*> vt;

int main() {
    int n, a, b; cin >> n >> a >> b;

    while (n) {
        int total = 0;
        vt teams(n);
        for (int i = 0; i < n; i++) {
            int k, da, db; cin >> k >> da >> db;
            teams[i] = new team(k, da, db);
        }

        sort(teams.begin(), teams.end(), [](team* t1, team* t2) {
            if (t1->k == 0)
                return false;
            if (t2->k == 0)
                return true;
            return t1->diff < t2->diff;
        });
        while (teams.size() && teams[teams.size() - 1]->k == 0)
            teams.pop_back();
        for (int i = 0; i < n && a && teams[i]->diff <= 0; i++) {
            if (teams[i]->k > a) {
                total += a * teams[i]->da;
                teams[i]->k -= a;
                a = 0;
            } else {
                total += teams[i]->k * teams[i]->da;
                a -= teams[i]->k;
                teams[i]->k = 0;
            }
        }

        sort(teams.begin(), teams.end(), [](team* t1, team* t2) {
            if (t1->k == 0)
                return false;
            if (t2->k == 0)
                return true;
            return t1->diff > t2->diff;
        });
        while (teams.size() && teams[teams.size() - 1]->k == 0)
            teams.pop_back();
        for (int i = 0; i < n && b; i++) {
            if (teams[i]->k > b) {
                total += b * teams[i]->db;
                teams[i]->k -= b;
                b = 0;
            } else {
                total += teams[i]->k * teams[i]->db;
                b -= teams[i]->k;
                teams[i]->k = 0;
            }
        }

        if (a) {
            sort(teams.begin(), teams.end(), [](team* t1, team* t2) {
                if (t1->k == 0)
                    return false;
                if (t2->k == 0)
                    return true;
                return t1->diff < t2->diff;
            });
            while (teams.size() && teams[teams.size() - 1]->k == 0)
                teams.pop_back();
            for (int i = 0; i < n && a; i++) {
                if (teams[i]->k > a) {
                    total += a * teams[i]->da;
                    teams[i]->k -= a;
                    a = 0;
                } else {
                    total += teams[i]->k * teams[i]->da;
                    a -= teams[i]->k;
                    teams[i]->k = 0;
                }
            }
        }

        cout << total << endl;
        cin >> n >> a >> b;
    }
    return 0;
}