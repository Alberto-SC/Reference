#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100007;

vector<int> graph[maxn];
vector<int> parent(maxn,-1);
vector<int> sz(maxn);
vector<int> depth(maxn);
vector<bool> centroid(maxn);

void dfs(int u,int p = -1,int d = 0){
    sz[u] = 1;
    depth[u] = d;
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u,d+1);
        sz[u]+=sz[v];
    }
}

vector<int> cont(maxn);
int k;
void dfs2(int u,int p= -1,int d = 0,bool f = true){
    if(f)cont[d]++;
    else cont[d]--;
    for(auto v:graph[u]){
        if(centroid[v] || v==p)continue;
        dfs2(v,u,d+1,f);
    }
}
int ans = 0;
void getAns(int u,int p= -1,int d = 0){
    if(d>k)return;
    ans+=cont[k-d];
    for(auto v:graph[u]){
        if(centroid[v]|| v==p)continue;
        getAns(v,u,d+1);
    }
}

int decomp(int u){
    int SZ = 1;
    for(auto v:graph[u])
        if(!centroid[v])
            SZ+=sz[v];
    
    while(1){
        int idx = -1;
        for(auto v:graph[u])
            if(!centroid[v] && sz[v]*2 > SZ)
                idx = v;
        if(idx ==-1)break;
        sz[u] = SZ-sz[idx];
        u = idx;
    }

    dfs2(u,-1,0,1);
    ans+=cont[k];
    for(auto v:graph[u]){
        if(!centroid[v]){
            dfs2(v,u,1,0);
            getAns(v,u,1);
            dfs2(v,u,1,1);
        }
    }
    dfs2(u,-1,0,0);

    centroid[u] = true;
    for(auto v:graph[u])
        if(!centroid[v])
            parent[decomp(v)] = u;

    return u;
}




signed main(){
    int n,u,v;
    cin>>n>>k;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0);
    decomp(0);
    cout<<ans/2<<endl;
    return 0;
}