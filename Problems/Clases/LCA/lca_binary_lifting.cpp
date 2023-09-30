#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

const int maxn = 200007;
vector<int> depth(maxn);
vector<int> graph[maxn];
int saltos[25][maxn];

void dfs(int u,int p = -1,int d = 0){
    depth[u] = d;
    saltos[0][u] = p;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u,d+1);
    }
}


void build(int n){
    for(int i = 0;i<25;i++)
        for(int j = 0;j<n;j++)
            saltos[i][j] = -1;

    dfs(0);

    for(int i = 1;i<25;i++)
        for(int u = 0;u<n;u++)
            if(saltos[i-1][u]!=-1)
                saltos[i][u] = saltos[i-1][saltos[i-1][u]];
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


signed main(){__
    int t = 1,n,u,v,q;
    cin>>n>>q;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }        

    build(n);

    for(int i = 0;i<q;i++){
        cin>>u>>v;
        u--,v--;
        int ans = depth[u]+depth[v]-(2*depth[lca(u,v)]);
        cout<<ans<<endl;
    }
    return 0;
}