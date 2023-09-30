#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int lli;

const int maxn =100007;
vector<bool> vis(maxn),bridge(maxn);
vector<lli> parent(maxn),sz(maxn),low(maxn),disc(maxn);
int idx;
set<int> graph[maxn];
void dfs(int u,int p = -1){
    disc[u] = idx++;
    low[u] = disc[u];
    parent[u] =p;
    sz[u] = 1;
    vis[u] = true;
    for(auto v:graph[u]){
        if(v == p)continue;
        if(!vis[v]){
            dfs(v,u);
            if(low[v]>disc[u])bridge[v] = true;
            sz[u]+=sz[v];
        }
        low[u] = min(low[u],low[v]);
    }   
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    for(int i = 0;i<n;i++){
        if(!vis[i])
            dfs(i);
    }
    for(int i =0;i<n;i++){
        vis[i] = false;
        if(bridge[i]){
            graph[i].erase(parent[i]);
            graph[parent[i]].erase(i);
        }
    }
    lli ans = 0;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
           dfs(i);
           ans += ((sz[i]-1)*sz[i])/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}