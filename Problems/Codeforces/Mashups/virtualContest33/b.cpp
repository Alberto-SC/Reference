#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> c(maxn);
vector<bool> vis(maxn);
int mn; 
void dfs(int u){
	vis[u] = true;
	mn = min(mn,c[u]);
	for(auto v: graph[u])
		if(!vis[v])
			dfs(v);
}

signed main(){__
	int t= 1,n,m,u,v;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++)
            cin>>c[i];
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                mn = 1e15;
                dfs(i);
                ans+=mn;
            }   
        }
        cout<<ans<<endl;
    }
    return 0;
}  
