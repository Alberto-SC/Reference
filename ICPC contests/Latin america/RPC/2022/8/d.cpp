#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100007;
vector<pair<int,int>> graph[maxn];
vector<pair<int,int>> graph2[maxn];
vector<int> alive(maxn);
vector<bool> vis(maxn);

void dfs(int u){
    vis[u] = true;
    for(auto v:graph[u]){
        if(vis[v.first])continue;
        dfs(v.first);
    }
}


signed main(){__
    int n,m,u,v,q,t,x;
    cin>>n>>m;
    for(int i =0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back({v,i});
        graph2[v].push_back({u,i});
    }
    cin>>q;
    vector<pair<int,int>> queries;
    int tm = 1;
    alive.assign(q,q);
    while(q--){
        cin>>t>>x;
        queries.push_back({t,x});
        if(t == 1)alive[x] = tm;
        tm++;
    }
    dfs(1);
    vector<int> A(n+1);
    for(int i = 1;i<=n;i++){
        A[i] = 0;
        for(auto v:graph2[i]){
            if(!vis[v.first])continue;
            A[i] = max(A[i],alive[v.second]);
        }
    }

    cout<<endl;
    for(int i = 1;i<=n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i = 1;i<=m;i++){
        cout<<alive[i]<<" ";
    }
    cout<<endl;
}