#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'
#define x first
#define y second
const int maxn = 200007;
vector<int> depth(maxn);
vector<pair<int,int>> graph[maxn];
struct E{
    int u,v,c,id;
};

int P[25][maxn];
int MX[25][maxn];



void dfs(int u,int p = -1,int d = 0,int c = 0){
    depth[u] = d;
    P[0][u] = p;
    MX[0][u] = c;
    for(auto v:graph[u]){
        if(v.x==p)continue;
        dfs(v.x,u,d+1,v.y);
    }
}


const int inf  = -1e15;
void build(int n){
    for(int i = 0;i<25;i++)
        for(int j = 0;j<n;j++)
            P[i][j] = -1,MX[i][j] = inf;

    dfs(0);
    for(int i = 1;i<25;i++){
        for(int u = 0;u<n;u++){
            if(P[i-1][u]!=-1)
                P[i][u] = P[i-1][P[i-1][u]];
            if(MX[i-1][u]!=inf)
                MX[i][u] = max(MX[i-1][u],MX[i-1][P[i-1][u]]);
        }
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int dist = depth[u]-depth[v];

    for(int i = 24;i>=0;i--){
        if((dist>>i)&1)
            u = P[i][u];
    }

    if(u== v)return u;

    for(int i = 24;i>=0;i--){
        if(P[i][u] != P[i][v]){
            u = P[i][u];
            v = P[i][v];
        }
    }
    
    return P[0][u];
}


vector<int> used(maxn);
vector<int> parent(maxn);
vector<int> sz(maxn,1);
int root(int u){
    return u ==parent[u]? u: parent[u] = root(parent[u]);
}

bool union_by_sz(int u,int v){
    u = root(u);
    v = root(v);
    if(u ==v)return false;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    parent[v] =u;
    return true;
}

int kruskal(vector<E> e){
    sort(e.begin(),e.end(),[&](E a,E b){
        return a.c<b.c;
    });
    int ans = 0;
    for(int i = 0;i<e.size();i++){ 
        int u= e[i].u,v = e[i].v,c = e[i].c;
        if(union_by_sz(u,v)){
            used[e[i].id] = true;
            graph[u].push_back({v,c});
            graph[v].push_back({u,c});
            ans+=c;
        }
    }
    return ans;
}

signed main(){
    int t = 1,n,u,v,c,m;
    cin>>n>>m;
    vector<E> e;
    for(int i = 0;i<m;i++){
        cin>>u>>v>>c;
        u--,v--;
        e.push_back({u,v,c,i});

    }        
    iota(parent.begin(),parent.end(),0);
    int mst = kruskal(e);

    build(n);
    for(int i = 0;i<m;i++){
        u = e[i].u;
        v = e[i].v;
        c = e[i].c;
        if(used[i])cout<<mst<<endl;
        else{
            int LCA = lca(u,v);
            int mx = inf;
            int dist_u_LCA = depth[u]-depth[LCA];
            for(int j = 24;j>=0;j--){
                if((dist_u_LCA>>j)&1){
                    mx = max(mx,MX[j][u]);
                    u = P[j][u];
                }
            }
            int dist_v_LCA = depth[v]-depth[LCA];
            for(int j = 24;j>=0;j--){
                if((dist_v_LCA>>j)&1){
                    mx = max(mx,MX[j][v]);
                    v = P[j][v];
                }
            }
            cout<<(mst-mx)+c<<endl;
        }
    }
    return 0;
}