#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

int mst(vvi edges, int V) {
    DS ds(V);
    sort(edges.begin(), edges.end());
    int mstWeight = 0;

    for (vi edge : edges) {
        int w = edge[0];
        int a = edge[1];
        int b = edge[2];

        if (ds.find(a) != ds.find(b)) {
            ds.merge(a, b);
            mstWeight += w;
        }
    }

    for (int i = 1; i < V; i++)
        if (ds.find(0) != ds.find(i))
            return -1;

    return mstWeight;
}

int main() {
    int n; cin >> n;

    for (int z = 1; z <= n; z++) {
        int V, E; cin >> V >> E;
        vvi edges(E);

        for (int i = 0; i < E; i++) {
            int a, b, w; cin >> a >> b >> w; a--; b--;
            edges[i] = { w, a, b };
        }

        int res = mst(edges, V);
        cout << "Campus #" << z << ": " << (res == -1 ? "I'm a programmer, not a miracle worker!" : to_string(res)) << endl;
    }

    return 0;
}