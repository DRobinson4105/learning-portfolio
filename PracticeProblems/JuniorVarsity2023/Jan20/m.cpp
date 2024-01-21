#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << fixed << setprecision(10);
    int n; cin >> n;
    while (n--) {
        double w, g, h, r; cin >> w >> g >> h >> r;

        double mini = sqrt(pow(h - g, 2) + pow(w, 2));
        h -= r; g -= r;
        if (!h && !g) {
            cout << mini << " " << mini << endl;
            continue;
        }
        double maxi = sqrt(pow(w * g / (g + h), 2) + pow(g, 2)) + 
                        sqrt(pow(w * h / (g + h), 2) + pow(h, 2));

        cout << mini << " " << maxi << endl;
    }
    return 0;
}