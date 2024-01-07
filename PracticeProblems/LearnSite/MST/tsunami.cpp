#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct Edge {
    int a, b;
    double w;
    Edge(int a, int b, double w) : a(a), b(b), w(w) {}
};

class DS {
public:
    int* arr;
    int* minY;

    DS(int n, vpii cities) {
        arr = new int[n];
        minY = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = -1; minY[i] = cities[i].second;
        }
    }

    int find(int x) {
        return (arr[x] < 0) ? x : (arr[x] = find(arr[x]));
    }

    int findMin(int x) {
        return minY[find(x)];
    }

    void merge(int a, int b) {
        int p1 = find(a), p2 = find(b);

        if (p1 == p2) return;

        arr[p1] += arr[p2];
        arr[p2] = p1;
        minY[p1] = min(minY[p1], minY[p2]);
    }
};

double mst(vector<Edge*>& edges, int V, vpii cities) {
    DS ds(V, cities);
    sort(edges.begin(), edges.end(), [](Edge* a, Edge* b) {
        return a->w < b->w;
    });

    double mstWeight = 0;

    for (Edge* edge : edges) {
        int a = edge->a, b = edge->b;

        if (ds.find(a) != ds.find(b)) {
            bool valid = false;
            bool leftValid = cities[a].second == ds.findMin(a);
            bool rightValid = cities[b].second == ds.findMin(b);

            if (cities[a].second > cities[b].second)
                valid = leftValid;
            else if (cities[a].second < cities[b].second)
                valid = rightValid;
            else valid = leftValid || rightValid;

            if (valid) {
                ds.merge(a, b);
                mstWeight += edge->w;
            }
        }
    }

    return mstWeight;
}

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    cout << fixed << setprecision(2);
    int n;

    while (cin >> n && n) {
        vpii cities(n);
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            cities[i] = {x, y};
        }

        sort(cities.begin(), cities.end(), [](pii a, pii b) {
            return a.second < b.second;
        });
        vector<Edge*> edges;

        int idx = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                edges.push_back(new Edge(i, j, dist(
                    cities[i].first, cities[i].second, cities[j].first, cities[j].second
                )));
            }
        }

        cout << mst(edges, n, cities) << endl;
    }
    return 0;
}