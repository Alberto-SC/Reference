#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 600007;
vector<int> p(maxn);
vector<int> sz(maxn,1);
vector<int> id(maxn); 

int root(int u){
    return p[u]== u?u:p[u] = p[u];
}

void union_by_size(int u,int v){
    u = root(u);
    v = root(v);
    if(u == v)return ;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    id[u] = v;
    id[v] = v;
}

signed main(){__
    int T = 1,n,u,v,q;
    cin>>n>>q;
    iota(p.begin(),p.end(),0);
    iota(id.begin(),id.end(),0);
    while(q--){
        int t;
        cin>>t;
        if(t ==1){
            cin>>u>>v;
            union_by_size(u,v);
        }
        else if(t==2){
            cin>>u;
            union_by_size(n+1,u);
            n++;
        }
        else {
            cin>>u;
            u = root(u);
            cout<<id[u]<<endl;
        }
    }
    return 0;
}