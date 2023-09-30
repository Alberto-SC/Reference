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

const int MX = 505;
int n, k, adj[MX][MX], ex[MX];

void main_() {
	cin >> n >> k;
	
	forn (i, n) {
		int m;
		cin >> m;
		
		while (m--) {
			int x;
			cin >> x;
			x--;
			
			adj[i][x] = 1;
		}
	}
	
	forn (i, n) {
		forn (j, n)
			ex[j] = 1;
		
		int cn = 1;
		ex[i] = 0;
		
		queue<int> q;
		q.push(i);
		
		while (q.size()) {
			int u = q.front();
			q.pop();
			
			forn (v, n)
				if (ex[v] && adj[v][u]) {
					ex[v] = 0;
					q.push(v);
					cn++;
				}
		}
		
		cout << int(cn > k) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
