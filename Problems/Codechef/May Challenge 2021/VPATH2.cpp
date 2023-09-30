#include <bits/stdc++.h>
using namespace std;
const int MX = 100000;
vector<int> G[MX];
int f[MX], sz[MX];
int dfs_sz(int v, int p = -1) {
	sz[v] = 1;
	for (int u : G[v]) {
		if (f[u] != 0 || u == p) continue;
		sz[v] += dfs_sz(u, v);
	}
	return sz[v];
}

void decomp(int v, int lev = 1) {
	int n = dfs_sz(v);
	bool ok = true;
	while (ok) {
		ok = false;
		for (int u : G[v])
			if (f[u] == 0 && sz[u] < sz[v] && sz[u] >= n / 2) {
				v = u;
				ok = true;
				break;
			}
	}
	sz[v] = n;
	f[v] = lev;
	for (int u : G[v]) if (f[u] == 0) decomp(u, lev + 1);
}

int K[MX], D[MX], cnt[MX], dep[MX], inside[MX + 1], depSize, insideSize;
void dfs_add(int v, int fv, int* a, int p = -1) {
	(*a)++;
	for (int u : G[v]) {
		if (u == p || f[u] <= fv) continue;
		dfs_add(u, fv, a + 1, v);
	}
}

void dfs_calc(int v, int fv, int p = -1, int w = 1) {
	if (D[v] >= w) {
		int x = D[v] - w;
		cnt[v] += dep[min(x, depSize - 1)];
		cnt[v] -= inside[min(x, insideSize - 1)];
	}
	
	for (int u : G[v]) {
		if (u == p || f[u] <= fv) continue;
		dfs_calc(u, fv, v, w + 1);
	}
}

int main() {
	int n;
    cin>>n;
    vector<int> K(n);
    iota(K.begin(),K.end(),1);
	for (int i = 1, u, v; i < n; i++) {
        cin>>u>>v;
		u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	decomp(0);
	for (int p = (1 << 16); p > 0; p /= 2) {
		for (int i = 0; i < n; i++) {
			D[i] += p;
			cnt[i] = 0;
		}
		for (int v = 0; v < n; v++) {
			depSize = sz[v];
			fill(dep, dep + depSize, 0);
			dfs_add(v, f[v], dep);
			partial_sum(dep, dep + depSize, dep);
			cnt[v] += dep[min(D[v], depSize - 1)];	
			for (int u : G[v])
				if (f[u] > f[v]) {
					dfs_add(u, f[v], inside + 1);
					insideSize = 1;
					while (inside[insideSize] > 0) insideSize++;
					partial_sum(inside, inside + insideSize, inside);
					dfs_calc(u, f[v]);
					fill(inside, inside + insideSize, 0);
				}
		}
		for (int i = 0; i < n; i++)
			if (cnt[i] + K[i] > n)
				D[i] -= p;
	}

	for (int i = 0; i < n; i++) printf("%d\n", D[i]);	
	return 0;
}