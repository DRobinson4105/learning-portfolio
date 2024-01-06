#include <bits/stdc++.h>

using namespace std;

struct Cable {
    int a, b;
    double w;
    Cable(int a, int b, double w) : a(a), b(b), w(w) {}
};

typedef vector<Cable*> vc;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class DS {
public:
    int* arr;

    DS(int n) {
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = -1;
    }

    int find(int x) {
        return (arr[x] < 0) ? x : (arr[x] = find(arr[x]));
    }

    void merge(int a, int b) {
        int p1 = find(a), p2 = find(b);

        if (p1 == p2) return;

        arr[p1] += arr[p2];
        arr[p2] = p1;
    }
};

double mst(vc edges, int V) {
    DS ds(V);
    sort(edges.begin(), edges.end(), [](Cable* a, Cable* b) {
        return a->w < b->w;
    });
    double mstWeight = 0;

    for (Cable* edge : edges) {
        double w = edge->w;
        int a = edge->a;
        int b = edge->b;

        if (ds.find(a) != ds.find(b)) {
            ds.merge(a, b);
            mstWeight += w;
        }
    }

    return mstWeight;
}

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
}

int main() {
    cout << fixed << setprecision(2);
    int n;

    while (cin >> n && n) {
        vpii poles(n);
        for (int i = 0; i < n; i++)
            cin >> poles[i].first >> poles[i].second;

        vc edges;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                edges.push_back(new Cable(i, j, dist(
                    poles[i].first, poles[i].second, poles[j].first, poles[j].second
                )));
            }
        }

        cout << mst(edges, n) << endl;
    }
    
    return 0;
}