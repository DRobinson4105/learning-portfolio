#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Tree {
	typedef long long T;
	static constexpr T starting = 1;
	T f(T a, T b) { return a + b; }
	vector<T> s;
	int n;
	Tree(int n = 0, T def = starting): s(2 * n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = starting, rb = starting;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main() {
    Tree* root = new Tree(6);

    assert(root->query(1, 6) == 4);
    root->update(4, 6); root->update(1, 2);
    assert(root->query(1, 6) == 12);

    return 0;
}