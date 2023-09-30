#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph[maxn];
vector<int> vis(maxn);

int ans = 0;

void dfs(int u){
    if(ans == 1000000)
        return;
    ans++;
    
    vis[u] = true;
    for(auto &v:graph[u]){
        if(vis[v])continue;
        dfs(v);
    }
    vis[u] = false;
}


signed main(){__
    int T = 1,n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}