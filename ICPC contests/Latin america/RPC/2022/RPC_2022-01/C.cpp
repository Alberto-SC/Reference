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

#define SET(p,n) memset(p, n, sizeof (p))

const int INF = INT_MAX;
const int MN = 100010, ME = 500010;

int src, snk, nno, ned;
int q[MN], fin[MN], pro[MN], dist[MN];
int flow[2*ME], cap[2*ME];
int sig[2*ME], to[2*ME];

inline void init (int _src, int _snk, int _n) {
	src = _src, snk = _snk, nno = _n, ned = 0;
	SET(fin, -1);
}

inline void add (int u, int v, int c) {
	to[ned] = v, cap[ned] = c, flow[ned] = 0, sig[ned] = fin[u], fin[u] = ned++;
	to[ned] = u, cap[ned] = 0, flow[ned] = 0, sig[ned] = fin[v], fin[v] = ned++;
}

inline void reset (int _src, int _snk) {
    src = _src, snk = _snk;
    for (int i = 0; i < ned; i++)
        flow[i] = 0;
}

bool bfs () {
	int st, en, u, v;
	SET(dist, -1);

	dist[src] = st = en = 0;
	q[en++] = src;

	while (st < en) {
		u = q[st++];

		for (int e = fin[u]; e >= 0; e = sig[e]) {
			v = to[e];

			if (flow[e] < cap[e] && dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}

	return dist[snk] != -1;
}

int dfs (int u, int mn) {
	if (u == snk)
		return mn;

	int au, v;
	for (int &e = pro[u]; e >= 0; e = sig[e]) {
		v = to[e];

		if (flow[e] < cap[e] && dist[v] == dist[u]+1)
			if (au = dfs(v, min(mn, cap[e] - flow[e]))) {
                flow[e] += au;
                flow[e^1] -= au;
                return au;
            }
	}

	return 0;
}

ll dinitz () {
	ll f = 0;
	int au;

	while (bfs()) {
		for (int i = 0; i <= nno; i++)
			pro[i] = fin[i];

		while (au = dfs(src, INF))
			f += au;
	}

	return f;
}

const int MX = 105;
int n, m, vis[MX][MX], cn = 1;
char c[MX][MX];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

int valid (int i, int j, char act) {
	if (i < 0 || n <= i) return 0;
	if (j < 0 || m <= j) return 0;
	if (c[i][j] != act) return -1;
	return 1;
}

void dfs (int i, int j, char c) {
	vis[i][j] = cn;
	
	forn (l, 4) {
		int x = i + mx[l];
		int y = j + my[l];
		
		if (valid(x, y, c) == 1 && !vis[x][y])
			dfs(x, y, c);
	}
}

void main_() {
	int s = 0, t = MN - 1;
	init(s, t, t);
	
	cin >> n >> m;
	forn (i, n)
		cin >> c[i];
	
	forn (i, n)
		forn (j, m)
			if (!vis[i][j]) {
				dfs(i, j, c[i][j]);
				
				if (c[i][j] == '0')
					add(s, cn, 1);
				else
					add(cn, t, 1);
				
				cn++;
			}
	
	forn (i, n)
		forn (j, m)
			forn (l, 4) {
				int x = i + mx[l];
				int y = j + my[l];
				int d = valid(x, y, c[i][j]);
				
				if (d == 0) {
					if (c[i][j] == '0') {
						add(vis[i][j], cn, 1);
						add(cn, t, 1);
					} else {
						add(s, cn, 1);
						add(cn, vis[i][j], 1);
					}
					cn++;
				} else if (d == -1) {
					if (c[i][j] == '0') {
						add(vis[i][j], vis[x][y], 1);
					}
				}
			}
	
	cout << dinitz() << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
