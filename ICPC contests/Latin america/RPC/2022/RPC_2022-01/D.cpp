#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353;
int n, dp[MX], acu[MX], sig[66];
ll a[MX];

void add (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}

void go () {
	forn (j, 60)
		sig[j] = n;
	
	dp[n] = 1;
	acu[n] = 1;
	
	for (int i = n - 1; i >= 0; i--) {
		int to = i + 1;
		
		forn (j, 60) {
			if (!(a[i] & (1ll << j)))
				sig[j] = i;
			to = max(to, sig[j]);
		}
		
		dp[i] = acu[i + 1];
		add(dp[i], -acu[to + 1]);

		acu[i] = acu[i + 1];
		add(acu[i], dp[i]);
	}
}

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	go();
	ll act = a[n - 1];
	int res = 0;
	
	forn (i, n) {
		if (!a[n - 1]) break;
		
		if (a[n - 1] != act) {
			go();
			act = a[n - 1];
		}
		
		a[n - 1] &= a[i];
		add(res, dp[i]);
	}
	
	if (a[n - 1])
		add(res, -n + 1);
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
