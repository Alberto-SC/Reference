#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 300007;
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
vector<int> depth(maxn);
int pa[25][maxn];

void dfs(int u,int p = -1,int d = 0){
    pa[0][u] = p;
    depth[u]= d;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u,d+1);
    }
}

void init(int n){
    for(int i = 0;i<n;i++)for(int j = 0;j<25;j++)pa[j][i] = -1;
    dfs(0);
    for(int j = 1;j<25;j++)
        for(int i = 0;i<n;i++)
            if(pa[j-1][i]!= -1)
                pa[j][i] = pa[j-1][pa[j-1][i]];
}

int lca(int u,int v){
    if(depth[u]>depth[v])swap(u,v);
    int diff = depth[v]-depth[u];
    for(int i = 24;i>=0;i--){
        if((diff>>i) &1)
            v = pa[i][v];
    }
    if(v == u)return u;
    for(int i = 24;i>=0;i--){
        if(pa[i][v] != pa[i][u]){
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][v];
}

int main(){__
    int n,u,v,c,q;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    init(n);
    // for(int i = 0;i<n;i++)cout<<depth[i]<<" ";
    // cout<<endl;
    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>u>>v>>c;
        u--,v--;
        int LCA = lca(u,v);
        int dist = depth[u]+depth[v]-(2*depth[LCA]);
        int dist_u_lca = depth[u]-depth[LCA];
        int dist_lca_u = depth[v]-depth[LCA];
        // cout<<LCA<<" "<<dist<<" "<<dist_lca_u<<" "<<dist_u_lca<<endl;
        if(dist<=c)cout<<v+1<<endl;
        else if(dist_u_lca>=c) {
            for(int k = 24;k>=0;k--)
                if((c>>k)&1)u = pa[k][u];
            cout<<u+1<<endl;
        }
        else{
            int diff = dist-c;
            for(int k = 24;k>=0;k--)
                if((diff>>k)&1)v = pa[k][v];
            cout<<v+1<<endl;
        }
    }

    return 0;
}

