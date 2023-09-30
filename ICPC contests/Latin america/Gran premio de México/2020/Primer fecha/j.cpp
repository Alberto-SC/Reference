#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, c, q, ft[MX];
map<int, int> mp, col;
set<int> no;

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

void update (int i, int j, int k) {
	auto it = mp.lower_bound(i);
	
	if (it != mp.begin()) {
		it--;
		
		if (j < it->se) {
			if (no.count(col[it->fi])) {
				update(i, 1);
				update(j + 1, -1);
			}
			
			mp[j + 1] = it->se;
			col[j + 1] = col[it->fi];
			
			it->se = i - 1;
		}
		
		if (i <= it->se) {
			if (no.count(col[it->fi])) {
				update(i, 1);
				update(it->se + 1, -1);
			}
			
			it->se = i - 1;
		}
		
		it++;
	}
	
	while (it != mp.end() && it->se <= j) {
		auto jt = it;
		it++;
		
		if (no.count(col[jt->fi])) {
			update(jt->fi, 1);
			update(jt->se + 1, -1);
		}
		
		mp.erase(jt);
	}
	
	if (it != mp.end() && it->fi <= j) {
		if (no.count(col[it->fi])) {
			update(it->fi, 1);
			update(j + 1, -1);	
		}
		
		mp[j + 1] = it->se;
		col[j + 1] = col[it->fi];
		mp.erase(it);
	}
	
	mp[i] = j;
	col[i] = k;
}

int find (int i) {
	if (query(i)) return -1;
	
	auto it = mp.upper_bound(i);
	if (it == mp.begin()) return 0;
	it--;
	if (it->se < i) return 0;
	
	if (no.count(col[it->fi])) return -1;
	return col[it->fi];	
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> c >> q;	
	while (q--) {
		char op;
		cin >> op;
		if (op == 'm') {
			int i, j, k;
			cin >> i >> j >> k;
			if (i > j) swap(i, j);
			update(i, j, k);
		} else if (op == 'b') {
			int k;
			cin >> k;
			assert(!no.count(k));
			no.insert(k);
		} else if (op == 'd') {
			int i;
			cin >> i;
			int res = find(i);
			if (res == -1) cout << "para que quieres saber eso" << endl;
			else if (res) cout << res << endl;
			else cout << "si lo encuentro que te hago" << endl;
		} else {
			int i, j;
			cin >> i >> j;
			if (find(i) == find(j)) cout << "si" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}
