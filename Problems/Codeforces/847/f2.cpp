#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 200007;
vector<int> graph[maxn];
vector<int> parent(maxn,-1);
vector<int> depth(maxn,-1);
vector<int> best(maxn,1e16);

int P[maxn][25];
bitset<maxn> cent;
int sz[maxn];
 
void dfs (int u, int p = -1,int d = 0) {
    sz[u] = 1;
    P[u][0] = p;
    depth[u] = d;
    for (int v : graph[u]){   
        if(v ==p)continue;
        dfs(v,u,d+1);
        sz[u] += sz[v];
    }
}
 
void build(int n,int root){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<25;j++)
            P[i][j] = -1;
    dfs(root);
    for(int i = 1;i<25;i++)
        for(int u = 0;u<n;u++)
            if(P[u][i-1]!=-1)
                P[u][i] = P[P[u][i-1]][i-1];
}
 
int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int diff = depth[u]-depth[v];
    for(int i = 24;i>=0;i--){
        if((diff>>i)&1){
            u = P[u][i];
        }
    }
    if(u==v)return u;
    for(int i= 24;i>=0;i--){
        if(P[u][i]!=P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}
 
int descomp (int u) {
    int tam = 1;
    for (int v : graph[u])
        if (!cent[v]) 
            tam += sz[v];
 
    while (1) {
        int idx = -1;
        for (int v : graph[u])
            if (!cent[v] && 2 * sz[v] > tam)
                idx = v;
        if (idx == -1)break;
        sz[u] = tam - sz[idx];
        u = idx;
    }
 
    cent[u] = 1;
    
	for (int v : graph[u])
        if (!cent[v])
            parent[descomp(v)] = u;
 
    return u;
}
 
int dist(int u,int v){
    return depth[u]+depth[v]-(2*depth[lca(u,v)]);
}
 
signed main(){__
    int T,n,u,v,root;
    cin>>T;
    while(T--){
        cin>>n>>root;
        root--;
        for(int i = 0;i<n;i++){
            graph[i].clear();
            cent[i] = 0;
            best[i] = 1e16;
            parent[i] = -1;
            depth[i] = -1;
            sz[i] = 0;
        }

        vector<int> q(n-1);
        for(auto &c:q)cin>>c,c--;

        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        build(n,root);
        descomp(root);

        u = root;
        while(u!=-1){
            best[u] = min(best[u],dist(u,root));
            u = parent[u];
        }

        int ans = 1e9;
        for(int i = 0;i<n-1;i++){
            v = q[i];
    
            int res = 1e15;
            u = v;
            while(u!=-1){
                
                res = min(res,best[u]+dist(v,u));
                u = parent[u];
            }  
            ans = min(ans,res);
            cout<<ans<<" ";
       
       
            u = v;
            while(u!=-1){
                best[u] = min(best[u],dist(u,v));
                u = parent[u];
            }
        }
        cout<<endl;
    }
}