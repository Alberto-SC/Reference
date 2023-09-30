#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int maxn = 100007;
vector<int> graph[maxn];
vector<int> color;

bool bipartite = true;
void dfs(int u,int p = -1){
    if(p==-1)
        color[u] = 0;
    else color[u] = color[p]^1;
    for(auto v:graph[u]){
        if(v==p)continue;
        if(color[v]== -1)dfs(v,u);
        else if(color[v]==color[u])bipartite = false;
    }
}


signed main(){__
    int n,m,u,v;
    cin>>n>>m;
    set<int> graph2[n];
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph2[u].insert(v);
        graph2[v].insert(u);
    }
    color.resize(n,-1);
    color[0] = 3;
    for(int i = 1;i<n;i++){
        if(!graph2[0].count(i))
            color[i] = 3;
    }
    for(auto c:graph2[0]){
        for(auto v:graph2[c]){
            if(color[v]==-1){
                graph[v].push_back(c);
                graph[c].push_back(v);
            }
        }
    }

    for(int i = 0;i<n;i++){
        if(color[i]==-1){
            dfs(i);
            break;
        }
    }
    bool flag = bipartite;
    vector<int> sz(3);
    for(int i = 0;i<n;i++){
        if(color[i]==-1)flag = false;
        else if(color[i]!=3)color[i]++;
        if(!flag)return cout<<-1<<endl,0;
        sz[color[i]-1]++;
    }
    for(int i = 0;i<n;i++){
        vector<int> sz2(3);
        for(auto c:graph2[i]){
            sz2[color[c]-1]++;
        }
        int x = sz2[0]+sz2[1]+sz2[2];
        if(sz2[color[i]-1]>0 || x!=(n-sz[color[i]-1]))flag = false;
    }
    if(!sz[0]||!sz[1]||!sz[2])flag = false;
    if(!flag)return cout<<-1<<endl,0;
    for(auto c:color)cout<<c<<" ";
    cout<<endl;
}