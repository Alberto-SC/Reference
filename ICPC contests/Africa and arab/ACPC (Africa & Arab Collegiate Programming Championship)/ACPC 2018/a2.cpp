#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
typedef long long int lli;

const int N   = 500050;
const int INF = 1e9+100;
ll sol,k,ans;
struct CentroidDecomposition {
	vector<vi> cd, &e;
	vector<bool> tocheck;
	vi size, p,cnt;
	int root;
	CentroidDecomposition(vector<vi> &tree) : e(tree) {
		int sz = e.size();
		tocheck.assign(sz, true);
		col.assign(sz, false);
		cd.assign(sz, vi());
		p.assign(sz, -1);
		cnt.assign(N, 0);
		size.assign(sz, 0);
		dfs(0);
		root = decompose(0, sz,-1);
	}
	void dfs(int u) {
		for (int v : e[u]) {
			if (v == p[u]) continue;
			p[v] = u;
			dfs(v);
			size[u] += 1 + size[v];
		}
	}
    void dfs2(int u,int p,int val,bool flag){
        if(flag) cnt[val]++;
        else cnt[val]--;
        for(auto v : e[u]){
            if(tocheck[v] && v!=p){
                dfs2(v,u,val+1,flag);
            }
        }

    }
    void solve(int u,int p,int val){
        if(val>k) return ;
        sol+=cnt[k-val];
        for(auto v : e[u]){
            if(tocheck[v] && v!=p){
                solve(v,u,val+1);
            }
        }
    }
    int decompose(int _u, int sz,int par) {
        int u = _u;
        while (true) {
            int nu = -1;
            for (int v : e[u]) {
                if (!tocheck[v] || v == p[u]) continue;
                if (1 + size[v] > sz / 2) nu = v;
            }
            if (sz - 1 - size[u] > sz / 2 && p[u] != -1
                &&tocheck[p[u]]) nu = p[u];
            if (nu != -1) u = nu; else break;
        }
        for (int v = p[u]; v != -1 && tocheck[v]; v = p[v])
            size[v] -= 1 + size[u];
        sol=0;
        dfs2(u,par,0,1);
        sol+=cnt[k];
        for(auto X : e[u]){
            if(tocheck[X]){
                dfs2(X,u,1,0);
                solve(X,u,1);
                dfs2(X,u,1,1);
            }
        }
        ans+=sol/2;
        dfs2(u,par,0,0);
        tocheck[u] = false;
        for (int v : e[u]) {
            if (!tocheck[v]) continue;
            int V2 = 1 + size[v];
            if (v == p[u]) V2 = sz - 1 - size[u];
            cd[u].push_back(decompose(v, V2,u));
        }
        return u;
    }
};

int main(){
	int n;
	cin>>n>>k;
	vector<vi> tree(n, vi());
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	CentroidDecomposition cd(tree);
	cout<<ans<<endl;
	return 0;
}