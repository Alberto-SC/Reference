
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int lli;

const lli mod = 1e9+7;
struct edge{
    int u,v,c;
    bool operator <(const edge A){
        return c<A.c;
    }
};
const int maxn = 100007;
vector<int> p(maxn);
vector<int> sz(maxn,1);

int get_root(int u){
    return u ==p[u]?u:p[u] = get_root(p[u]);
}
void union_by_size(int u,int v){
    u = get_root(u);
    v = get_root(v);
    if(u ==v)return;
    if(sz[v]>sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
}

int nextInt() {
    int x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

int main(){__
    int n,u,v,c;
    n = nextInt();
    iota(p.begin(),p.end(),0);
    vector<edge> edges;
    for(int i =0;i<n-1;i++){
        u = nextInt();
        v = nextInt();
        c = nextInt();
        edges.push_back({u,v,c});
    }
    sort(edges.begin(),edges.end());
    lli ans = 0;
    for(int i  = 0;i<n-1;i++){
        lli x = sz[get_root(edges[i].u)];
        lli y = sz[get_root(edges[i].v)];
        union_by_size(edges[i].u,edges[i].v);
        lli pt = (x*y)%mod;
        ans+= edges[i].c*pt;
        if(ans>10000*mod)ans%=mod;
    }
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}