#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int k;
const int maxn = 100007;
vector<int> p(maxn);
vector<int> sz(maxn,1);

lli mod_pow(lli a,lli b,lli mod){
    lli x = 1;
    while(b){
        if(b&1) x = (a*x)%mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

int root(int u){
    return p[u] == u?u:p[u] = root(p[u]);
}

void union_sz(int u,int v){
    u = root(u);
    v = root(v);
    if( u == v)return;
    if(sz[v]> sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    k--;
}
int main(){
    lli n,m,mod,u,v;
    cin>>n>>m>>mod;
    iota(p.begin(),p.end(),0);
    k = n;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        union_sz(u,v);
    }
    lli x = 1;
    vector<bool> used(n);
    for(int i = 0;i<n;i++){
        if(!used[root(i)]){
            x*=sz[root(i)];
            x%=mod;
            used[root(i)] = true;
        }
    }
    if(k == 1)return cout<<1%mod<<endl,0;
    lli y = mod_pow(n,k-2,mod);
    (x*=y)%=mod;
    cout<<x<<endl; 
    return 0;
}