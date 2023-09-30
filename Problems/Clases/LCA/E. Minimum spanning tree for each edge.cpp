#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

const int maxn = 200007;
vector<int> depth(maxn);
vector<int> graph[maxn];
int saltos[25][maxn];
int MX[25][maxn];

void dfs(int u,int p = -1,int d = 0){
    depth[u] = d;
    saltos[0][u] = p;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u,d+1);
    }
}

const int inf = -1e15;

void build(int n){
    for(int i = 0;i<25;i++)
        for(int j = 0;j<n;j++)
            saltos[i][j] = -1,MX[i][j] = inf;

    dfs(0);

    for(int i = 1;i<25;i++){
        for(int u = 0;u<n;u++){
            if(saltos[i-1][u]!=-1)
                saltos[i][u] = saltos[i-1][saltos[i-1][u]];
            if(MX[i-1][u]!= inf)
                MX[i][u] = max(MX[i-1][u],MX[i-1][saltos[i-1][i]]);
        }
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int dist = depth[u]-depth[v];

    for(int i = 24;i>=0;i--){
        if((dist>>i)&1)
            u = saltos[i][u];
    }

    if(u== v)return u;

    for(int i = 24;i>=0;i--){
        if(saltos[i][u] != saltos[i][v]){
            u = saltos[i][u];
            v = saltos[i][v];
        }
    }
    
    return saltos[0][u];
}


struct E{
    int u,v,c,id;
};

int root(int u){
    return u==parent[u]?u:parent[u] = root(parent[u]);
}

vector<int> parent(maxn);
vector<int> sz(maxn);
bool union_by_sz(int u,int v){
    u = root(u);
    v = root(v);
    if(u== v)return false;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    parent[v] = u;
}

int krustal(vector<E> e){
    sort(e.begin(),e.end(),[&](E a,E b){
        return a.c<b.c;
    });

    int ans = 0;
    for(int i = 0;i<e.size();i++){
        int u = e[i].u,v = e[i].v,c = e[i].c;
        if(union_by_sz(u,v)){
            used[e[i].id] = true;
            graph[u].push_back(v);
            graph[v].push_back(u);
            ans+=c;
        }
    )
    return ans;
}

signed main(){__
    int t = 1,n,u,v,c;
    cin>>n>>m;
    vector<E> e;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v>>c;
        u--,v--;
        e.push_back({u,v,c,i});
    }        

    int mst = krustal(e);
    build(n);

    for(int i = 0;i<m;i++){
        u = e[i].u;
        v = e[i].v;
        c = e[i].c;
        if(used[i])cout<<mst<<endl;
        else{
            int mx = inf;
            int LCA = lca(u,v);
            int dist_u_lca = depth[u]-depth[lca];
            for(int j = 24;j>=0;j--){
                if((dist_u_lca>>j)&1){
                    max(mx,MX[j][u]);
                    u = saltos[j][u];
                } 
            }
            int dist_v_lca = depth[v]-depth[lca];
            for(int j = 24;j>=0;j--){
                if((dist_v_lca>>j)&1){
                    max(mx,MX[j][v]);
                    v = saltos[j][v];
                } 
            }
            cout<<(mst-mx)+c;
        }
    }
    return 0;
}