#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<int> p;
vector<int> size(maxn,1);

int raiz(int u){
    return u == p[u]?u:p[u] = raiz(p[u]);
}

bool conexos(int u,int v){
    return raiz(u) == raiz(v);
}
void union_bySize(int u,int v){
    u = raiz(u);
    v = raiz(v);
    if(u!= v){
        if(size[u]<size[v])swap(u,v);
        size[u]+=size[v];
        p[v] = u;
    }
}
int mn[maxn];
int main(){
    int n,m,u,v;
    cin>>n>>m;
    p.resize(n);
    iota(p.begin(),p.end(),0);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        union_bySize(u,v);
    }
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        int comp = raiz(i);
        int pos = mn[comp];
        for(int j = i + 1; j < pos; j++) {
            if(conexos(i,j))continue;
            ans++;
            union_bySize(i, j);
        }
        comp = raiz(i);
        mn[comp] = i;
    }
    cout<<ans<<endl;
    return 0;
}