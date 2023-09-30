#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int cont = 0;
const int maxn = 1007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
void dfs(int u){
    vis[u] = true;
    cont++;
    for(auto v:graph[u]){
        if(!vis[v])
            dfs(v);
    }
}

signed main(){__
	int t= 1,n,p,u,v;
    while(t--){
        cin>>n>>p;
        for(int i = 0;i<p;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>_all;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cont = 0;
                dfs(i);
                _all.push_back(cont);
            }
        }
        vector<int> M(1007);
        int ans = 0;
        M[0] = 1;
        for(int i = 0; i < _all.size(); i++)
            for(int j = 1000; j >= _all[i]; j--) 
                M[j] |= M[j -_all[i] ];
        
        for(int i = 1;i<=n;i++){
            if(M[i])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
