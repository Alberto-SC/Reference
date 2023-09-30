#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int maxn = 100007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
vector<int> parent(maxn);
vector<int> lvl(maxn);
int ans = 1e16;

void dfs(int u,int p = -1,int d= 0){
    vis[u] = true;
    lvl[u] = d;
    for(auto v:graph[u]){
        if(v == p)continue;
        if(!vis[v]){
            parent[v] = u;
            dfs(v,u,d+1);
        }
        else if(vis[v] && lvl[v]<lvl[u]){
            ans = min(ans,(lvl[u]-lvl[v])+1);
        }
    }
}

signed main(){__
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int start = 0;start<n;start++){
        vis.assign(n,false);

        for(int i = 0;i<n;i++){
            if(!vis[(i+start)%n])
                dfs((i+start)%n);
        }
    }
    if(ans == 1e16)
        cout<<-1<<endl;
    else cout<<ans<<endl;
}