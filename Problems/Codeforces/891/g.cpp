#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const long long mod = 998244353;
const int maxn = 200007;


long long  bin_pow(long long a,long long b){
    long long x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}


vector<int> p(maxn),sz(maxn);

int root(int u){
    return u == p[u]?u:p[u] = root(p[u]);
}

long long union_by_size(int u,int v){
    u = root(u);
    v = root(v);
    
    long long res = (long long)sz[u]*sz[v];
    if(sz[u]<sz[v])swap(u,v);
    p[v] = u;
    sz[u]+=sz[v];
    return res;
}

struct E{
    int u,v,w;

    bool operator<(const E &e)const{
        if(w==e.w){
            if(u==e.u)
                return v<e.v;
            return u<e.u;
        }
        return w<e.w;
    }
};


signed main(){__
    int T = 1,n,S;
    cin>>T;
    
    while(T--){
        cin>>n>>S;
        for(int i = 0;i<n;i++)p[i] = i,sz[i] = 1;
        vector<E> edges(n-1);
        

        for(int i = 0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            edges[i] = {u,v,w};
        }

        sort(edges.begin(),edges.end());
        long long ans = 1;
        for(int i = 0;i<edges.size();i++){
            int u = edges[i].u,v = edges[i].v,w = edges[i].w;
            long long x = union_by_size(u,v);

            ans*=bin_pow((S-w)+1,x-1);
            ans%=mod;
        }

        cout<<ans<<endl;
    }   
    return 0;
}