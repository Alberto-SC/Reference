#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> sz(maxn),parent(maxn),vis(maxn),level(maxn);
int P[25][maxn];
vector<int> depth(maxn);
int find_size(int u,int p = -1){
    if(vis[u])return 0;
    sz[u] = 1;
    for(auto v:graph[u]){
        if(v == p)continue;
        sz[u]+=find_size(v,u);
    }
    return sz[u];
}

int find_centroid(int u,int p,int n){
    for(auto v:graph[u]){
        if(v == p)continue;
        if(!vis[v] && sz[v]>n/2)
            return find_centroid(v,u,n);
    }
    return u;
}

void decompose(int u = 0,int p = -1,int lvl = 0){
    find_size(u);
    int c = find_centroid(u,-1,sz[u]);
    parent[c] = p;
    vis[c] = 1;
    level[c] = lvl;
    for(auto v:graph[c]){
        if(vis[v])continue;
        decompose(v,c,lvl+1);
    } 
}

void dfs(int u,int p = -1,int d = 0){
    depth[u] = d;
    P[0][u] = p;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u,d+1);
    }
}

void init(int n){
    dfs(0);
    for(int i = 1;i<25;i++){
        for(int j = 0;j<n;j++){
            if(P[i-1][j] != -1)
                P[i][j] = P[i-1][P[i-1][j]];
        }
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int diff = depth[u]-depth[v];
    for(int i = 24;i>=0;i--){
        if((diff>>i) &1)
            u = P[i][u];
    }
    if(u == v)return u;
    for(int i =24;i>=0;i--){
        if(P[i][u] != P[i][v]){
            u = P[i][u];
            v = P[i][v];
        }
    }
    return P[0][v];
}
const int inf =1e9;
vector<int> best(maxn,inf);
int dist(int u,int v){
    int LCA = lca(u,v);
    // cout<<"LCA "<<LCA<<endl;
    return depth[u]+depth[v]-(2*depth[LCA]);
}
void update(int u){
    int v = u;
    do{
        best[v] = min(best[v],dist(u,v));
        v = parent[v];
    }while(v!= -1);
}

int query(int u){
    int v = u;
    int ans = best[u];
    do{
        ans = min(ans,best[v]+dist(u,v));
        v = parent[v];
    }while(v!= -1);
    return ans;
}
int main(){
    int n,u,v,m;
    cin>>n>>m;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    decompose();
    init(n);
    update(0);
    for(int i = 0;i<m;i++){
        int type;
        cin>>type>>u;
        u--;
        if(type == 1)
            update(u);
        else
            cout<<query(u)<<endl;
    
    }
    return 0;
}