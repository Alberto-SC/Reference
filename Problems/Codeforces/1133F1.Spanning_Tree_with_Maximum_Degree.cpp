#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
const int maxn = 200007;
vector<int> p(maxn);
vector<int> sz(maxn,1);
vector<int> degree(maxn);
vector<int> graph[maxn];
int get_root(int u){
    return u == p[u]?u:p[u]= get_root(p[u]);
}

bool union_by_sz(int u,int v){
    u = get_root(u);
    v = get_root(v);
    if(u ==v)return false;

    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    return true;
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    iota(p.begin(),p.end(),0);
    vector<pair<int,int>> edges;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        edges.push_back({u,v});
        degree[u]++;
        degree[v]++;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    int mx= 0,mxn;
    for(int i = 0;i<n;i++){
        if(degree[i]>mx){
            mx = degree[i];
            mxn = i;
        }
    }
    for(auto v:graph[mxn]){
        cout<<v+1<<" "<<mxn+1<<endl;
        union_by_sz(mxn,v);
    }
    for(auto [u,v]:edges){
        if(union_by_sz(u,v))
            cout<<u+1<<" "<<v+1<<endl;
        
    }

    return 0;
}