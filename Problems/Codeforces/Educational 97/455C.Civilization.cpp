#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn = 300007; 
vector<int> graph[maxn];

vector<int> p(maxn);
vector<int> sz(maxn,1);
vector<int> dim(maxn);
int top;
int q[maxn+7];
vector<bool> vis(maxn);
int mx = -1,node;
void dfs(int u,int p = -1,int d = 0){
    vis[u] = true;
    if(d>mx){
        mx = d,
        node = u;
    }
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u,d+1);
    }
}

int get_root(int u){
    return p[u]== u?u:p[u] = get_root(p[u]);
}

void union_size(int u,int v){
    u = get_root(u);
    v = get_root(v);
    if(u ==v)return;
    if(sz[v]>sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
}


int main(){__
    int n,m,q,u,v,x,t;
    cin>>n>>m>>q;
    iota(p.begin(),p.end(),0);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--; 
        union_size(u,v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            top = 0;
            mx = -1;
            dfs(i);
            mx = -1;
            dfs(node);
            int root = get_root(i);
            dim[root] = mx;

        }
    }
    // for(int i = 0;i<n;i++){
        // cout<<get_root(i)<<" "<<dim[get_root(i)]<<endl;
    // }

    for(int i = 0;i<q;i++){
        cin>>t;
        if(t ==1){
            cin>>x;
            x--;
            cout<<dim[get_root(x)]<<endl;
        }
        else{
            cin>>u>>v;
            u--,v--;
            if(get_root(u)== get_root(v))continue;
            int d1 = dim[get_root(u)];
            int d2 = dim[get_root(v)];
            union_size(u,v);
            int root = get_root(u);
            dim[root] = max({((d1+1)>>1) + ((d2+1)>>1) +1,d1,d2});
        }
    }
    return 0;
}