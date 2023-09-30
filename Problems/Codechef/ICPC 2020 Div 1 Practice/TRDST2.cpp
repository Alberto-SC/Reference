#include <bits/stdc++.h>
#define PB push_back
#define X first
#define Y second
#define INF 1000 * 1000 * 1000
#define LL long long
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;
const int MAX = 1 << 17;
int N;
int K[MAX];
int D[MAX];
int val[MAX];
int ans[MAX];
int sub[MAX];
int deleted[MAX];
int depth[MAX];
int cnt[MAX];
int pref[MAX];
int cnt2[MAX];
int pref2[MAX];
vector<vector<int> > g(MAX);
void dfs(int u , int p = -1){
	sub[u] = 1;
	for(auto v : g[u]){
		if(!deleted[v] && v != p){
			dfs(v , u);
			sub[u] += sub[v];
		}
	}
}
int mxDepth2 = 0;
int mxDepth = 0;
void dfs1(int u , int p = -1){
	mxDepth = max(mxDepth , depth[u]);
	cnt[depth[u]]++;
	for(auto v : g[u]){
		if(v != p && !deleted[v]){	
			depth[v] = depth[u] + 1;
			dfs1(v , u);
		}
	}
}
void dfs2(int u , int p = -1){
	mxDepth2 = max(mxDepth2 , depth[u]);
	cnt2[depth[u]]++;
	for(auto v : g[u]){
		if(v != p && !deleted[v]){
			dfs2(v , u);
		}
	}
}
int suma , Suma;
void dfs3(int u , int p = -1){
	int glyb = val[u] - depth[u];
	if(glyb >= 0){
		ans[u] += (glyb <= mxDepth ? pref[glyb] : Suma) - (glyb <= mxDepth2 ? pref2[glyb] : suma) ;
	}
	for(auto v : g[u]){
		if(v != p && !deleted[v]){
			dfs3(v , u);
		}
	}
}
void go(int u){
	dfs(u);
	int sz = sub[u];
	int centr = u;
	while(true){
		bool was = false;
		for(auto v : g[centr]){
			if(!deleted[v] && sub[v] < sub[centr] && sub[v] * 2 > sz)
				centr = v , was = true;
		}
		if(!was)
			break;
	}
	mxDepth = 0;
	depth[centr] = 0;
	dfs1(centr);
	for(int i = 0; i <= mxDepth; i++)
		pref[i] = cnt[i] + (i ? pref[i - 1] : 0);
	Suma = pref[mxDepth];
	if(val[centr] <= mxDepth)
		ans[centr] += pref[val[centr]];
	else	
		ans[centr] += Suma;
	
	for(auto v : g[centr]){
		if(!deleted[v]){
			mxDepth2 = 0;
			dfs2(v , centr);
			for(int i = 0; i <= mxDepth2; i++){
				pref2[i] = cnt2[i] + (i ? pref2[i - 1] : 0);
			}
			suma = pref2[mxDepth2];
			//cout << v  << " " << suma << endl;
			dfs3(v , centr);
			for(int i = 0; i <= mxDepth2; i++)
				cnt2[i] = 0;
		}
	}
	for(int i = 0; i <= mxDepth; i++)
		cnt[i] = 0;
	deleted[centr] = 1;
	for(auto v : g[centr]){
		if(!deleted[v])
			go(v);
	}
}

vector<int> solve(){
	for(int i = 0; i < N; i++){
		val[i] = 0;
	}
	for(int i = 16; i >= 0; i--){
		memset(deleted , 0 , sizeof deleted);
		for(int j = 0; j<N ; j++){
			val[j] += (1 << i);
			ans[j] = 0;
		}
		go(0);
		for(int j = 0; j < N; j++){
			if(ans[j] > K[j])
				val[j] -= (1 << i);
		}
	}
	vector<int> Ans(N);	
	for(int i = 0; i < N; i++)
		Ans[i] = val[i];
	return Ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> K[i];
		K[i] = N - K[i];
	}
	for(int i = 1; i < N; i++){
		int u , v;
		cin >> u >> v;
		u--;v--;
		g[u].PB(v);
		g[v].PB(u);
	}
	vector<int> Distances = solve();
	for(int i = 0; i < Distances.size(); i++){
		cout << Distances[i] << " ";
	}
	
}
