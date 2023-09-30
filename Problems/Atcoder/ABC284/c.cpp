#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 10007;
vector<int> padre(maxn);
vector<int> sz(maxn,1);
int raiz(int v){
    return v== padre[v]?v:padre[v] = raiz(padre[v]);
}
int ans ;
void union_bySize(int u,int v){
    u = raiz(u);
    v = raiz(v);
    if (u != v) {
        ans--;
        if (sz[u] < sz[v])
            swap(u, v);
        padre[v] = u;
        sz[u] += sz[v];
    }  
}

signed main(){__
    int T = 1,n,m;
    cin>>n>>m;
    ans = n;
    iota(padre.begin(),padre.end(),0);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        union_bySize(u,v);
    }
    cout<<ans<<endl;
    return 0;
}