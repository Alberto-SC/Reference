#include <bits/stdc++.h>
using namespace std;
const int maxn = 600007;
vector<int> sz(maxn,1);
vector<int> p(maxn);

int get_raiz(int u){
    return u== p[u]?u:p[u] = get_raiz(p[u]);
}

void union_bySize(int u,int v){
    u = get_raiz(u);
    v = get_raiz(v);
    if(u!= v){
        if(sz[u]<sz[v])
            swap(u,v);
        p[v] = u;
        sz[u]+=sz[v];
    } 
}
int main(){
    int n,m,x,v;
    cin>>n>>m;
    iota(p.begin(),p.end(),0);
    for(int i = 0;i<m;i++){
        cin>>x;
        int last;
        for(int j = 0;j<x;j++){
            cin>>v;
            if(j)
                union_bySize(v,last);
            last = v;
        }
    }
    for(int i = 1;i<=n;i++)
        cout<<sz[get_raiz(i)]<<" ";
    cout<<endl;
    return 0;
}