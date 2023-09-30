#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const int mxlog = 25;
vector<int> graph[maxn];
int parent[mxlog][maxn];
vector<int> deep(maxn);

typedef long long int ll;

int N;
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void dfs(int u,int p = -1,int d = 0){
    deep[u] = d;
    parent[0][u] = p;
    for(auto v:graph[u]){
        if(v== p)continue;
        dfs(v,u,d+1);
    }
}

void build(){
    for(int i = 0;i<N;i++)
        if(deep[i]== -1)dfs(i);

    for(int i = 1;i<mxlog;i++){
        for(int u = 0;u<N;u++){
            if(parent[i-1   ][u]!= -1)
            parent[i][u] = parent[i-1][parent[i-1][u]];
        }
    }
}

int lca(int u ,int v){
    if(deep[u]>deep[v])swap(u,v);
    int diff = deep[v]-deep[u];
    for(int i = mxlog-1;i>=0;i--){
        if(diff & (1<<i))
            v = parent[i][v];
    }
    if(u == v)return u;

    for(int i = mxlog-1;i>=0;i--){
        if(parent[i][u]!= parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}
void init(){
    for(int i = 0;i<N;i++)for(int j = 0;j<mxlog;j++)parent[j][i] = -1;
    for(int i = 0;i<N;i++)deep[i]= -1;
    dfs(0);
    build();
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,u,v;
    cin>>n>>q;
    N = n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    init();
    for(int i = 0;i<q;i++){
        cin>>u>>v;
        u--,v--;
        int LCA = lca(u,v);
        ll dist = deep[u]+deep[v]-(2*deep[LCA])+1;
        ll res= n + (((dist)*(dist-1))>>1) ;
        cout<<res<<"\n";
    }

    return 0;
}
