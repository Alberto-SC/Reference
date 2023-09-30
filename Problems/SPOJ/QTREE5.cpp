#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

const int maxn = 100007;
vector<int> graph[maxn];
vector<int> sz(maxn);
vector<int> parent(maxn,-1);
vector<int> depth(maxn);
vector<bool> centroid(maxn);
int P[maxn][25];

void dfs(int u,int p = -1,int d = 0){
    sz[u] = 1;
    depth[u] = d;
    P[u][0] = p;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u,d+1);
        sz[u]+=sz[v];
    }
}

void build(int n){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<25;j++)
            P[i][j] = -1;
    dfs(0);
    for(int i = 1;i<25;i++)
        for(int u = 0;u<n;u++)
            if(P[u][i-1]!=-1)P[u][i]= P[P[u][i-1]][i-1];
}

int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int diff = depth[u]-depth[v];
    for(int i = 24;i>=0;i--)
        if((diff>>i)&1)u = P[u][i];
    if(u==v)return v;
    for(int i= 24;i>=0;i--){
        if(P[u][i]!=P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}

int dist(int u,int v){
    return depth[u]+depth[v]- (2*depth[lca(u,v)]);
}

int decompose(int u){
    int SZ = 0;
    for(auto v:graph[u])
        if(!centroid[v])SZ+=sz[v];
    
    while(1){
        int idx = -1;
        for(auto v:graph[u])
            if(!centroid[v] && 2*sz[v]>SZ)
                idx = v;
        if(idx==-1)break;
        sz[u]= SZ-sz[idx];
        u = idx;        
    }

    centroid[u] = true;
    for(auto v:graph[u])
        if(!centroid[v])
            parent[decompose(v)] = u;
    return u;
}

signed main(){
    int n,q,u,v,x;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    build(n);
    decompose(0);
    cin>>q; 
    multiset<int> ans[n];
    for(int i = 0;i<q;i++){
        cin>>x>>v;
        v--;
        if(x==0){
            u = v;
            bool flag = false;
            if(ans[u].count(0))flag = true;
            while(u!=-1){
                if(flag)
                    ans[u].erase(ans[u].find(dist(u,v)));
                else
                    ans[u].insert(dist(u,v));
                u = parent[u];
            }
        }
        else{
            int res = 1e15;
            u = v;
            
            while(u!=-1){
                if(ans[u].size())
                    res = min(*ans[u].begin()+dist(u,v),res);
                u = parent[u];
            }
            if(res==1e15)
                cout<<-1<<endl;
            else
                cout<<res<<endl;
        }
    }

}