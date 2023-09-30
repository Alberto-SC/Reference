#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int solve(ll med, vector <vector <ll>> &a, int n, ll l, ll r) {
	int ans = 0;
	for (auto &vec : a) {
		ll sum = 0;
		for (int i = 0; i < n; ++i) sum += vec[i];
		int op = 0;
		if (sum < med) {
			for (int i = 0; i < n && sum < med; ++i) {
				sum += r - vec[i];
				op++;
			}
			if (sum < med) op = 1e9;
		} else if (sum > med) {
			for (int i = n - 1; i >= 0 && sum > med; --i) {
				sum -= vec[i] - l;
				op++;
			}
			if (sum > med) op = 1e9;
		}
		ans = max(ans, op);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tt; cin >> tt;
	while (tt--) {
		int k, n; ll l, r; cin >> k >> n >> l >> r;
		vector <vector <ll>> a(k, vector <ll> (n));
		vector <ll> b(k);
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
			sort(a[i].begin(), a[i].end());
		}
		ll lo = 1ll * l * n, hi = 1ll * r * n;
		while (hi - lo > 3ll) {
			ll m1 = lo + (hi - lo) / 3ll, m2 = hi - (hi - lo) / 3ll; 
			int o1 = solve(m1, a, n, l, r), o2 = solve(m2, a, n, l, r);
			if (o1 > o2) lo = m1;
			else if (o1 < o2) hi = m2;
			else lo = m1, hi = m2;
		}
		int ans = 1e9;
		while (lo <= hi) {
			ans = min(ans, solve(lo, a, n, l, r));
			lo++;
		}
		if (k == 1) ans = 0;
		cout << ans << '\n';
	}
	return 0;
}

