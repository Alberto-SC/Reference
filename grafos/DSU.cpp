#include <bits/stdc++.h>
using namespace std; 
vector<int> padre;
vector<int> sz;
int raiz(int v){
    return v== padre[v]?v:padre[v] = raiz(padre[v]);
}
void union_bySize(int u,int v){
    u = raiz(u);
    v = raiz(v);
    if (u != v) {
        if (sz[u] < sz[v])
            swap(u, v);
        padre[v] = u;
        sz[u] += sz[v];
    }  
}
bool same(int u,int v){
    return (raiz(u) == raiz(v));
}
int main(){
    int n,u,v;
    for(int i = 0;i<n;i++)padre[i] = i,sz[i] = 1;
    for(int n = 0;i<n;i++){
        cin>>u>>v;
        union_bySize(u,v);
    }
    int mx = *max_element(sz.begin(),sz.end());
    cout<<mx<<endl,
    return 0;
}