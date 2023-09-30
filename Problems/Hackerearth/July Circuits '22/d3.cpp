#include <bits/stdc++.h>
using namespace std;

const int inf = 0;
struct ST {
	int N;
	vector<int> t;
	ST(int n) {
		N = n;
		t.assign(4 * n + 10, inf);
	}
	int merge(int L, int R) {
		return max(L, R);
	}
	void update(int n, int b, int e, int i, int x) {
		if (b > i || e < i) return;
		if (b == e && b == i) {
			t[n] = max(x, t[n]);
			return;
		}
		int mid = (b + e) >> 1, l = n << 1, r = l | 1;
		update(l, b, mid, i, x);
		update(r, mid + 1, e, i, x);
		t[n] = merge(t[2 * n], t[2 * n + 1]);
	}
	int query(int n, int b, int e, int i, int j) {
		if (b > j || e < i || i > j) return inf;
		if (b >= i && e <= j) return t[n];
		int mid = (b + e) >> 1, l = n << 1, r = l | 1;
		int L = query(l, b, mid, i, j);
		int R = query(r, mid + 1, e, i, j);
		return merge(L, R);
	}
	int query(int L, int R) {
		return query(1, 1, N, L, R);
	}
	int query(int pos) {
		return query(1, 1, N, pos, pos);
	}
	void update(int pos, int val) {
		update(1, 1, N, pos, val);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> m;
		ST st1(n), st2(n), st3(n);
		int mx = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			int y = 1 + max(st3.query(1, 1, n, 1, x - 1), st1.query(1, 1, n, 1, x - 1));
			int z = 1 + max(st3.query(1, 1, n, x + 1, n), st2.query(1, 1, n, x + 1, n));
			int mx = 1 + m[x];
			m[x] = max({y, z, mx});
			ans = max(ans, max({mx, y, z}));
			st1.update(x, y);
			st2.update(x, z);
			st3.update(x, mx);
		}
		cout << ans << '\n';
	}
}



