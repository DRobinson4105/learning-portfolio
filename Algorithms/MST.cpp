#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct DS {
	vi s;
	DS(int n): s(n, -1) {}
	int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (s[a] > s[b]) swap(a, b);
		s[a] += s[b], s[b] = a;
		return true;
	}
	int size(int i) { return -s[find(i)]; }
	bool same(int a, int b) { return find(a) == find(b); }
};

int mst(vvl edges, int V) {
    DS ds(edges.size());
    sort(edges.begin(), edges.end());
    int mstWeight = 0;

    for (vl edge : edges) {
        int w = edge[0];
        int a = edge[1];
        int b = edge[2];

        if (ds.find(a) != ds.find(b)) {
            ds.merge(a, b);
            mstWeight += w;
        }
    }

    for (int i = 1; i < V; i++)
        if (!ds.same(0, i)) return -1;

    return mstWeight;
}

int main() {
    vvl edges = {{1, 0, 1}, {2, 0, 3}, {3, 1, 2}, {1, 2, 3}, {3, 0, 2}};

    assert(mst(edges, 4) == 4);
    return 0;
}