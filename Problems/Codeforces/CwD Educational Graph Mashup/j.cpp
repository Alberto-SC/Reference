#include <bits/stdc++.h>
using namespace std;
typedef long long int lli; 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn = 200007;
vector<int> graph[maxn];
vector<int> disc(maxn),low(maxn),vis(maxn),bridge(maxn),value(maxn);
int idx;
void dfs(int u,int p = -1){
    disc[u] = idx++;
    vis[u] = 1;
    low[u] = disc[u];
    for(auto v:graph[u]){
        if(v == p)continue;
        if(!vis[v]){
            dfs(v,u);
            if(low[v]>disc[u])bridge[v] = 1;
        }
        low[u] = min(low[u],low[v]);
    }
}

lli ans = 0;
vector<bool> used(maxn);
bool dfs2(int u){
    bool flag = false;
    vis[u] = true;
    for(auto v:graph[u]){
        if(!vis[v])
            flag|= dfs2(v);
    }
    if(!bridge[u]|| flag){
        used[u] = true;
        ans+=value[u];
        return true;
    }
    return false;
}

lli res;
void dfs3(int u,lli val){
    if(used[u]||vis[u])return;
    vis[u] = true;
    for(auto v:graph[u]){
        if(!vis[v])
            dfs3(v,val+value[v]);
    }
    res = max(res,val);
}
int main(){__
    int n,s,u,v,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        cin>>value[i];
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin>>s;
    s--;
    dfs(s);
    vis.assign(n,0);
    dfs2(s);
    vis.assign(n,0);
    vector<int> f;
    for(int i = 0;i<n;i++)
        if(!used[i])f.push_back(i);
    sort(f.begin(),f.end(),[&](int u,int v){
        return disc[u]<disc[v];
    });
    lli mx = 0;
    for(auto v:f){
        res = 0;
        dfs3(v,value[v]);
        mx = max(mx,res);
    }
    ans+=mx;
    cout<<ans<<endl;
    return 0;
}