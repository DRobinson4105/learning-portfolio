#include <bits/stdc++.h>
using namespace std;

struct DS {
	vector<int> s;
	DS(int n): s(n, -1) {}
	DS(vector<int> vec): s(vec) {}

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
	int largest() { return -*min_element(s.begin(), s.end()); }
};