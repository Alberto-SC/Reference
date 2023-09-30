// Powered by CP Editor (https://cpeditor.org)

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

int n, t[10];
ll mem[10][10][10], s;

ll dp (int i, int a, int b) {
	if (i == n) return 1;
	
	ll &res = mem[i][a][b];
	if (res != -1) return res;
	res = 0;
	
	forn (x, t[i]) {
		int na = x / 10;
		int nb = x % 10;
		
		if (b * 10 + na < t[i] && b * 10 + nb < t[i])
			res += dp(i + 1, na, nb);
	}
	
	return res;
}

void main_() {
	cin >> n;
	s = 1;
	
	forn (i, n) {
		cin >> t[i];
		s *= t[i];
	}
	
	memset(mem, -1, sizeof(mem));
	cout << s - dp(0, 0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
